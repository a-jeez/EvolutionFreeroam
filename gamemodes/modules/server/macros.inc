#define SERVER_NAME "Punix"
#define SERVER_VERSION _date

//MySQL Macros
#define MYSQL_HOSTNAME "127.0.0.1"
#define MYSQL_USERNAME "root"
#define MYSQL_PASSWORD "9KrtrGf.=0TIjQRPcShWE+x9"
#define MYSQL_DATABASE "evofr"

//Utility
#define function%0(%1) forward public %0(%1); public %0(%1)

//Messages
#define Error(%1,%2) SendClientMessage(%1, -1, "{A9A9A9}ERROR: "%2)
