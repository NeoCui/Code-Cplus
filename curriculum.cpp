#include "curriculum.h"
//how to connect sql statement to string
//how to return and show result
void ListCur(MysqlDB& mysql){
	cout<<"List all the curriculum in shcool."<<endl;
	string sql;
	sql = "select * from curriculum";
	mysql.ShowRecord(sql);
	while(mysql.res->next()){
		cout<<"ID:"<<mysql.res->getInt("ID")<<endl;
		cout<<"Course Name:"<<mysql.res->getString("CurName")<<endl;
		cout<<"Course Time:"<<mysql.res->getString("CurTime")<<endl;
		cout<<"Course Score:"<<mysql.res->getInt("Score")<<endl;
		cout<<"Course Teacher:"<<mysql.res->getString("Teacher")<<endl;
}

void AddCur(MysqlDB& mysql){
	string name;
	string time;
	int score;
	string teacher;
	cout<<"Add a new curriculum."<<endl;
	cout<<"Curriculum Name:";
	cin>>name;
	cout<<"Curriculum Time:";
	cin>>time;
	cout<<"Curriculum Score:";
	cin>>score;
	cout<<"Curriculum Teacher:";
	cin>>teacher;

	string sql;
	sql = "insert into curriculum(CurName, CurTime, Score, Teacher) values("+name+","+time+","+score+","+teacher+")";
	mysql.ExcuteSQL(sql);
}

void DeleteCur(MysqlDB& mysql){
	cout<<"Delete a curriculum."<<endl;
	cout<<"which curriculum you want to delete:";
	string name;
	cin>>name;
	string sql;
	sql = "delete from curriculum where CurName = "+name;
	mysql.ExcuteSQL(sql);
}
		
void GetCur(MysqlDB& mysql){
	cout<<"Get the curriculum you want to know."<<endl;
	cout<<"which curriculum you want to know:";
	string name;
	cin>>name;
	string sql;
	sql = "select * from curriculum where CurName = "+name;
	mysql.ShowRecord(sql);
	cout<<"Course Information:"<<endl;
	cout<<mysql.res->getString("CurName")<<"/"<<mysql.res->getString("CurTime")
		<<"/"<<mysql.res->getInt("score")<<"/"<<mysql.res->getString("Teacher")<<endl;
}
		
void GetCurByTeacher(MysqlDB& mysql, string teacher){
	cout<<"Get the curriculum you want to know."<<endl;
	cout<<"which teacher's curriculum you want to know:";
	string teacher;
	cin>>teacher;
	string sql;
	sql = "select * from curriculum where Teacher="+teacher;
	mysql.ShowRecord(sql);
	cout<<"Course Information:"<<endl;
	cout<<mysql.res->getString("CurName")<<"/"<<mysql.res->getString("CurTime")
		<<"/"<<mysql.res->getInt("score")<<"/"<<mysql.res->getString("Teacher")<<endl;
}
	
