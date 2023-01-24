#include "storage.h"
#include "orm.h"
#include "secrets.h"
pg::connection db;
void connect_to_db()
{
   /**
 * @brief Usage example:
 * @code {.cpp}
 * config->user = "dba";
   config->password = "password, which was set in Postgres";
   config->host = "127.0.0.1"; // "localhost" doesn't work by default!
   config->dbname = "db_name"; // or default db
 * @endcode
 */
   auto config = std::make_shared<pg::connection_config>();
   config->user = secret_db_username;
   config->password = secret_db_password;
   config->host = secret_db_host;
   config->dbname = secret_dbname;

   db = pg::connection(config);
}
