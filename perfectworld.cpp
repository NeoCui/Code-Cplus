#include<iostream>
#include<vector>

using namespace std;

//test for jinritoutiao
int func(int n){
	static int i=1;
	n=n+i;
	i++;
	if(n<5){
		cout<<n<<"\\";
		n=n+func(n);
	}
	return n;
}
//the use of lower_bound and upper_bound
void Verify1(){
	int a[]={12,17,17,22,22,23,30};
	vector<int> v(a,a+7);
	vector<int>::iterator iter,location;
	location=lower_bound(v.begin(),v.end(),17);
	cout<<location-v.begin()<<endl;
	location=upper_bound(v.begin(),v.end(),22);
	cout<<location-v.begin()<<endl;
}
//unsignedint to int
int Verify2(){
	int i=(int)((unsigned int)0xffffffff+(unsigned int)0xffffffff);
	return i;
}
//The question of a&(a-1)
void Verify3(){
	int a;
	int count=0;
	cin>>a;
	while(a){
		a=a&(a-1);
		count++;
	}
	cout<<count<<endl;
}
class A{
public:
	A(){}
	virtual ~A(){};
	int m_x;
};

int main(int argc, char** argv){
	cout<<"Test for jrtt:"<<func(1)<<endl;
	Verify1();
	cout<<Verify2()<<endl;
	Verify3();
	float a=0;
	if(a>-0.00001&&a<0.00001)
		cout<<"true"<<endl;
	A aa;
	cout<<sizeof(aa)<<endl;
	return 0;
}
