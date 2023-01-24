#ifndef ECOSYSTEM_STORAGE_H
#define ECOSYSTEM_STORAGE_H

#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/postgresql/connection.h>

namespace pg = sqlpp::postgresql;
extern pg::connection db;
void connect_to_db();

#endif
