#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool Comp(const string& a, const string& b){
	size_t pos1,pos2;
	int numa,numb;
	pos1=a.find('.');
	pos2=a.find('.');
	numa=atoi(a.substr(0,pos1).c_str());
	numb=atoi(b.substr(0,pos2).c_str());
	if(numa>numb){
		return a>b;
	}else{
		return a<b;
	}
}

int main(){
	vector<string> input;
	int T;
	string temp;
	cin>>T;
	cin.ignore();
	while(T--){
		getline(cin,temp);
		input.push_back(temp);
	}
	sort(input.begin(),input.end(),Comp);
	int num;
	size_t pos1,pos2;
	string end_str;
	while(1){
		end_str=input.back();
		pos1=end_str.find('.');
		pos2=end_str.find('.',pos1+1);
		num=atoi(end_str.substr(pos1+1,pos2).c_str());
		if(num%2==0){
			cout<<end_str<<endl;
			break;
		}
		input.erase(input.end()-1);
	}
	return 0;
}
