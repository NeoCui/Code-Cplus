#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class empty{};

class base{
public:
	base(){
		cout<<"base construction."<<endl;
	};
	virtual void Virtual(){
		cout<<"virtual base"<<endl;
	}
	void fun(){
		Virtual();
	}
	~base(){
		cout<<"base deconstruction"<<endl;
	}
};

class derived:public base{
public:
	derived(){
		cout<<"derived construction."<<endl;	
	}
	void Virtual(){
		cout<<"virtual derived."<<endl;
	}
	~derived(){
		cout<<"derived deconstrucion."<<endl;
	}
};

int main(){
	base ob;
	base* pob=new derived();
	derived obb;
	ob.fun();
	obb.fun();
	pob->fun();
	cout<<"empty class size:"<<sizeof(empty)<<endl;
return 0;
}
