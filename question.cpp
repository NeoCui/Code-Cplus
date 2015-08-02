#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<stack>

using namespace std;
//string to int
void ConvertStr(string n, long&);
//10to2
void FConvert(long n, vector<long>&);
//primer detection
void GetPrimer(long n, vector<long>&);
int main(int argc, char** argv){
	//10to2
	cout<<"Convert 10 to 2"<<endl;
	vector<long> bit;
	FConvert(11,bit);
	vector<long>::iterator it=bit.begin();
	while(it != bit.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	//primer detection
	cout<<"Get Primer:"<<endl;
	vector<long> primer;
	GetPrimer(100,primer);
	vector<long>::iterator it1=primer.begin();
	while(it1 != primer.end()){
		cout<<*it1<<" ";
		++it1;
	}
	cout<<endl;
	//string to int
	string str = "1234567";
	long value = 0;
	ConvertStr(str,value);
	cout<<"Integer:"<<value<<endl;
	return 0;
}
void FConvert(long n, vector<long>& bit){
	stack<long> tempstack;
	long temp = n;
	while(temp != 1){
		long temp1 = temp%2;
		tempstack.push(temp1);
		temp = temp/2;
	}
	tempstack.push(1);
	while(tempstack.empty() == false){
		bit.push_back(tempstack.top());
		tempstack.pop();
	}
}

void GetPrimer(long n, vector<long>& primer){
	if(n == 1){
		cout<<"No primer."<<endl;
		return;
	}
	if(n == 2){
		primer.push_back(2);
		return;
	}
	for(long index=3; index<=n; index=index+2){
		bool isP = true;
		for(long j=3; j<=sqrt(index); j=j+2){
			if(index%j ==0){
				isP = false;
				break;
			}
		}
		if(isP){
			primer.push_back(index);
		}
	}
}

void ConvertStr(string str, long& value){
	value = 0;
	string::size_type index = 0;
	for(; index<str.size(); ++index){
		char m = '0';
		char p = '9';
		if(str[index]>m && str[index]<p){
			long temp = str[index]-48;
			value = value*10+temp;
		}
	}
}
