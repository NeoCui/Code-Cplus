/*student.h*/
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include<iostream>
#include<string>
#include<vector>

#include "mysqldb.h"

using namespace std;

class Student{
	//initialization, load\insert\delete\alter\search information from db
	public:
		Student(string name, int id):name(""),id(0){}
		~Student();
		void GetStudent(MysqlDB& mysql);
	
		void GetCur(MysqlDB& mysql);

		void AddCur(MysqlDB& mysql);

		void DeleteCur(MysqlDB& mysql);

	private:
		string name;
		int id;
};
#endif
