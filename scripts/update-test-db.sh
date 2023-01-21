psql -c "DROP DATABASE test;" -c "CREATE DATABASE test;"; psql -U $USER test < ./architecture/first-level/component-storage/CSt.db-script.sql
