#ifndef COMPONENT_OBJECT_REGISTRATION_N
#define COMPONENT_OBJECT_REGISTRATION_N

#include <boost/asio/signal_set.hpp>
#include <boost/network/protocol/http/server.hpp>
#include <cassert>
#include <memory>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace http = boost::network::http;

struct request_handler;
using server = http::server<request_handler>;

#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/select.h>
#include <sqlpp11/alias_provider.h>
#include <sqlpp11/insert.h>
#include <sqlpp11/postgresql/connection.h>
#include <sqlpp11/postgresql/postgresql.h>
#include "DB.h"

namespace sql = sqlpp::postgresql;
database::EcosystemUser u = {};
database::EcosystemDevice d = {};
database::EcosystemUserDevice ud = {};
const auto now = ::sqlpp::chrono::floor<::std::chrono::microseconds>(std::chrono::system_clock::now());
auto config = std::make_shared<sql::connection_config>();
sql::connection db;

int registration(std::string _name, std::string _login, std::string _password, int _type, long long _hardwaveid)
{
	auto tx = sqlpp::start_transaction(db);
	int c;
	for (const auto& row : db(sqlpp::select(count(u.userId)).from(u).where(u.login == _login)))
	{
		c = row.count;
		if (c != 0) return -1;
	}
	db(sql::insert_into(u).set(u.name = _name, u.login = _login, u.password = _password));
	c = -1;
	for (const auto& row : db(sqlpp::select(d.deviceId).from(d).where(d.hardwareId == _hardwaveid)))
		c = row.deviceId;
	long long idu, idd;
	if (c == -1)
	{
		db(sql::insert_into(d).set(d.type = _type, d.hardwareId = _hardwaveid));
		for (const auto& row : db(sqlpp::select(d.deviceId).from(d).order_by(d.registrationTime.desc()).limit(1u).unconditionally()))
			idd = row.deviceId;
	}
	else idd = c;
	for (const auto& row : db(sqlpp::select(u.userId).from(u).where(u.login == _login)))
		idu = row.userId;
	db(sql::insert_into(ud).set(ud.deviceId = idd, ud.userId = idu));
	tx.commit();
	return 0;
}

int authorization(std::string _login, std::string _password, int _type, long long _hardwaveid)
{
	long long idu = -1, idd = -1;
	for (const auto& row : db(sqlpp::select(u.userId).from(u).where(u.login == _login && u.password == _password)))
		idu = row.userId;
	if(idu == -1) throw std::exception("Неправильный логин или пароль!\n");
	for (const auto& row : db(sqlpp::select(d.deviceId).from(d).where(d.hardwareId == _hardwaveid)))
		idd = row.deviceId;
	if (idd == -1)
	{
		db(sql::insert_into(d).set(d.type = _type, d.hardwareId = _hardwaveid));
		for (const auto& row : db(sqlpp::select(d.deviceId).from(d).order_by(d.registrationTime.desc()).limit(1u).unconditionally()))
			idd = row.deviceId;
		db(sql::insert_into(ud).set(ud.deviceId = idd, ud.userId = idu));
	}
	db(update(ud).set(ud.isActive = true).where(ud.deviceId == idd && ud.userId == idu));
	return 0;
}

int sign_out(std::string _login, std::string _password, long long _hardwaveid)
{
	long long idu, idd;
	for (const auto& row : db(sqlpp::select(u.userId).from(u).where(u.login == _login && u.password == _password)))
		idu = row.userId;
	for (const auto& row : db(sqlpp::select(d.deviceId).from(d).where(d.hardwareId == _hardwaveid)))
		idd = row.deviceId;
	db(update(ud).set(ud.isActive = false).where(ud.deviceId == idd && ud.userId == idu));
	return 0;
}
#endif