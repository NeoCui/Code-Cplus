/*mysqldb.h*/
#ifndef _MYSQLDB_H_ 
#define _MSYQLDB_H_
#include<iostream>
#include<string>
#include<vector>

#include "mysql_connection.h"
#include<cppconn/driver.h>
#include<cppconn/exception.h>
#include<cppconn/resultset.h>
#include<cppconn/statement.h>
#include<cppconn/prepared_statement.h>

using namespace std;

class Student;
class Curriculum;

class MysqlDB{
	//initialization, load\insert\delete\alter\search information from db
	public:
		MysqlDB(bool isServerConnected, bool isDBConnected)
			:isServerConnected(false), isDBConnected(false){};
		~MysqlDB(){
			if(isServerConnected){
				con->close();
				delete res;
				delete stmt;
				delete pstmt;
				delete con;	
			}
		}
		//connect to server tcp://127.0.0.1:3306 root 123456
		bool ConnectServer(string serverName, string userName, string pwd);
		//Disconnect to server
		void DisconectServer(){
			con->close();
		}
		//Connect to table
		bool ConnectDB(string dbName);
		//excute sql statement
		bool ExcuteSQL(string sql);
		//represent the result
		bool ShowRecord(string sql);
		//dabtabase initialization
		void MysqlInit(MysqlDB &sql);
		//user log in
		int Login(string name, string pwd);

		friend class Student;
		friend class Curriculum;
	
	private:
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		bool isServerConnected;
		bool isDBConnected;
};
#endif
