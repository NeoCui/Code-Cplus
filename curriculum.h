/*curriculum.h*/
#ifndef _CURRICULUM_H_
#define _CURRICULUM_H_
#include<iostream>
#include<string>
#include<vector>

#include "mysqldb.h"

using namespace std;

class Curriculum{
	//initialization, load\insert\delete\alter\search information from db
	public:
		Curriculum(int curid, string curname, string curtime, int score, string teacher):
						curid(0),curname(""),curtime(""),score(0),teacher(""){}
		~Curriculum();
		void ListCur(MysqlDB& mysql);

		void AddCur(MysqlDB& mysql);

		void DeleteCur(MysqlDB& mysql);
		
		void GetCur(MysqlDB& mysql);
		
		void GetCurByTeacher(MysqlDB& mysql);
	
	private:
		string curname;
		int id;
		string curtime;
		int score;
		string teacher;
};
#endif
