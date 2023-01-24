//#include <windows.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include <boost/network/protocol/http/client.hpp>
namespace http = boost::network::http;

std::string url = "http://127.0.0.1:8000/";
const int _type = 2;
long long _hardwaveid = 29;

http::client client;
http::client::request request(url);

std::string _name;
std::string _login;
std::string _password;

void registration(std::string name, std::string login, std::string password, int type, long long hardwaveid);
void authorization(std::string login, std::string password, int type, long long hardwaveid);
void sign_out(std::string login, std::string password, long long hardwaveid);
//void work()

int main()
{
	int m;
	bool ex = false;
	request << ::boost::network::header("Connection", "close");
	while (!ex)
	{
		try
		{
			std::cout << "Выберите действие:\n(1) Регистрация\n(2) Авторизация\n(3) Выход\n";
			std::cout << ">> ";
			std::cin >> m;
			if (m >= 1 && m <= 3)
			{
				switch (m)
				{
				case 1:
					std::cout << "Введите имя, логин и пароль:\n";
					std::cout << ">> ";
					std::cin >> _name;
					std::cout << ">> ";
					std::cin >> _login;
					std::cout << ">> ";
					std::cin >> _password;
					registration(_name, _login, _password, _type, _hardwaveid);
					break;
				case 2:
					std::cout << "Введите логин и пароль:\n";
					std::cout << ">> ";
					std::cin >> _login;
					std::cout << ">> ";
					std::cin >> _password;
					authorization(_login, _password, _type, _hardwaveid);
					//sleep(5000);
					sign_out(_login, _password, _hardwaveid);
					break;
				case 3:
					ex = true;
					break;
				}
			}
			else throw std::exception("Введены неверные данные!\n");
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

void registration(std::string name, std::string login, std::string password, int type, long long hardwaveid)
{
	json js = { {"name", name}, {"login", login}, {"password", password}, {"type", type}, {"hardwave_id", hardwaveid} };
	request << ::boost::network::body(js.dump());
	http::client::response response = client.post(request);
	std::cout << body(response) << std::endl;
}

void authorization(std::string login, std::string password, int type, long long hardwaveid)
{
	json js = { {"login", login}, {"password", password}, {"type", type}, {"hardwave_id", hardwaveid} };
	request << ::boost::network::body(js.dump());
	http::client::response response = client.get(request);
	std::cout << body(response) << std::endl;
}

void sign_out(std::string login, std::string password, long long hardwaveid)
{
	json js = { {"login", login}, {"password", password}, {"hardwave_id", hardwaveid} };
	request << ::boost::network::body(js.dump());
	http::client::response response = client.delete_(request);
	std::cout << body(response) << std::endl;
}