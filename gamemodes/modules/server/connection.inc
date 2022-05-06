//MySQL R41-4 (latest)
new MySQL:Database;

MySQL_Connect()
{
	new MySQLOpt: option_id = mysql_init_options();

	mysql_set_option(option_id, AUTO_RECONNECT, true);

    Database = mysql_connect(MYSQL_HOSTNAME, MYSQL_USERNAME, MYSQL_PASSWORD, MYSQL_DATABASE, option_id);

    if(Database == MYSQL_INVALID_HANDLE || mysql_errno(Database) != 0)
    {
        print("[MySQL]: Failed to establish connection with MySQL server.");
        return 1;
    }
    print("[MySQL]: Success establish connection with MySQL server.");
    mysql_query(Database, "CREATE TABLE IF NOT EXISTS accounts (id INT(16) NOT NULL AUTO_INCREMENT PRIMARY KEY, name VARCHAR(25) NOT NULL, password VARCHAR(64) NOT NULL)", false);
    return 1;
}
