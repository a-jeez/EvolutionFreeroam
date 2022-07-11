//Server Macros
#define SERVER_NAME "Punix"
#define SERVER_VERSION _date

//MySQL Macros
#define MYSQL_HOSTNAME "127.0.0.1"
#define MYSQL_USERNAME "root"
#define MYSQL_PASSWORD ""
#define MYSQL_DATABASE "evofr"

//Utility
#define function%0(%1) forward public %0(%1); public %0(%1)
#define stock2%0(%1) stock %0(%1)
#define DEFAULT_POS_X 	1958.3783
#define DEFAULT_POS_Y 	1343.1572
#define DEFAULT_POS_Z 	15.3746
#define DEFAULT_POS_A   270.1425

//Messages
#define Error(%1,%2) SendClientMessage(%1, -1, INDIANRED1"[ERROR]:"WHITE" "%2)
#define Server(%1,%2) SendClientMessage(%1, -1, INDIANRED1"[SERVER]:"WHITE" "%2)
#define Usage(%1,%2) SendClientMessage(%1, -1, INDIANRED1"[USAGE]:"WHITE" "%2)
