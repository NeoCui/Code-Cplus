#include "student.h"

void Student::GetStudent(MysqlDB& mysql){
	string sql;
	sql = "select * from student where Name = "+name;
	mysql.ShowRecord(sql);
	cout<<"User Name:"<<mysql.res->getString("Name")<<endl;
	cout<<"User ID:"<<mysql.res->getInt("ID")<<endl;
}

void Student::GetCur(MysqlDB& mysql){
	string sql;
	sql = "select * from stucur where StudentID = "+id;
	mysql.ShowRecord(sql);
	while(mysql.res->next()){
		cout<<"curriculumID:"<<mysql.res->getInt("CurID")<<endl;
	}
}

void Student::AddCur(MysqlDB& mysql){
	string curid;
	cout<<"Input the course id you want to add:";
	cin>>curid;
	string sql;
	sql = "insert into stucur(StudentID, CurID) values('"+id+","+curid;
	mysql.ExcuteSQL(sql);
}

void Student::DeleteCur(MysqlDB& mysql){
	string curid;
	cout<<"Input the course id you want to delete:";
	cint>>curid;
	string sql;
	sql = "delete from stucur where CurID = "+curid;
	mysql.ExcuteSQL(sql);
}
