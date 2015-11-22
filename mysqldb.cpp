/*mysqldb.cpp*/
#include<iostream>
#include<string>
#include<vector>

#include "mysqldb.h"

using namespace std;

//connect to server tcp://127.0.0.1:3306 root 123456
bool MysqlDB::ConnectServer(string serverName, string userName, string pwd){
	try{
		driver = get_driver_instance();
		con = driver->connection(serverName, userName, pwd);
	}catch(sql::SQLException &e){
		cout<<"#ERR: "<<e.what();
		cout<<"(MySQL error code: "<<e.getErrorCode();
		cout<<",SQLState: "<<e.getSQLState()<<")"<<endl;
		isServerConnected = false;
		return false;
	}
	isServerConnected = true;
	return true;
}
//Disconnect to server
void MysqlDB::DisconectServer(){
	isServerConnected = false;
	con->close();
}
//Connect to table
bool MysqlDB::ConnectDB(string dbName){
	if(!con->setSchema(dbName)){
			cout<<"Table connect failed."<<endl;
			isDBConnected = false;
			return false;
	}else{
		isDBConnected = true;
		return true;
	}
}
//excute sql statement
bool MysqlDB::ExcuteSQL(string sql){
	stmt = con->createStatement();
	res = stmt->executeQuery(sql);
	if(res->rowsCount == 0){
		cout<<"No operation"<<endl;
		return false;
	}else{
		return true;
	}
}
//represent the result
bool MysqlDB::ShowRecord(string sql){
	//under construction
	if(isDBConnected == false){
		cout<<"Not conncet to any databases."<<endl;
		return false;
	}
	stmt = con->createStatement();
	res = stmt->executeQuery(sql);
	if(res){
		return true;
	}else{
		cout<<"No record"<<endl;
		return false;
	}
}

//databse initialization
void MysqlDB::MysqlInit(MysqlDB &sql){
	sql.ConnectServer("tcp://127.0.0.1:3306", "root", "123456");
	sql.ExcuteSQL("create database if not exists class");
	sql.ConnectDB("class");
	
	sql.ExcuteSQL("create table if not exists student(StudentID int auto_increment, Name varchar(15), primary key(StudentID))");
	sql.ExcuteSQL("create table if not exists curriculum(CurID int auto_increment, CurName varchar(20), CurTime timestamp,
		Score int, Teacher varchar(15), primary key(CurID))");
	sql.ExcuteSQL("create table if not exists stucur(ID int auto_increment, StudentID int, CurID int, constraint fk_1 
		foreign key(StudentID) references student(StudentID) on update cascade on delete restrict),
			foreign key(CurID) references curriculum(CurID) on update cascade on delete restrict");
	
}
//user login
int MysqlDB::Login(string name, string pwd){
	if(name == "root"){
		cout<<"Administrator login"<<endl;
		return 0;
	}else{
		string sql;
		sql = "select password from student where Name = "+name;
		ShowRecord(sql);
		if(res){
			if(res->getString("password") == pwd){
				cout<<name<<" login successfully."<<endl; 
				return res->getInt("StudentID");
			}
		}else{
			cout<<"No student name is:"<<name<<endl;
			return -1;
		}
	}
}
