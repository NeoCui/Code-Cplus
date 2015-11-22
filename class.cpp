#include<iostream>
#include<string>
#include "mysqldb.h"
#include "student.h"
#include "curriculum.h"

using namespace std;

void root(MysqlDB& mysql){
	Curriculum root;
	root.ListCur(mysql);
	root.AddCur(mysql);
	root.DeleteCur(mysql);
	root.GetCur(mysql);
	root.GetCurByTeacher(mysql);
	root.ListCur(mysql);
}

void student(MysqlDB& mysql,string name,int id){
	Student stu(name,id);
	stu.GetStudent(mysql);
	stu.GetCur(mysql);
	stu.AddCur(mysql);
	stu.DeleteCur(mysql);
}

int main(void){
	string uname;
	string upwd;
	int utype;
	MysqlDB mysql;
	mysql.MysqlInit(mysql);

	while(1){
		cout<<"User login..."<<endl;
		cout<<"name:";
		cin>>uname;
		cout<<"password:";
		cin>>upwd;
		utype = mysql.Login(uname, upwd);
		if(utype<0){
			continue;
		}else{
			break;
		}
	}

	switch(utype){
		case 0:
			cout<<"Administrator:"<<uname<<endl;
			root(mysql);
			break;
		case 1:
			cout<<"Student:"<<uname<<endl;
			student(mysql, uname, utype);
			break;
		default:
			cout<<"Warning!"<<endl;
			break;
	}

	cout<<"Bye..."<<endl;
	return 0;
}
