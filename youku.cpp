#include<iostream>
#include<string>
#include<vector>

using namespace std;

string& Decode(string& input){
	int N=input.size();
	string* ret=new string();
	string str_temp="";
	string str_buffer="";
	vector<string> buffer;
	vector<int> count;
	for(int i=0; i<N; ++i){
		char temp=input.at(i);
		if(temp<48 || temp>57){
			str_temp+=temp;
		}else{
			count.push_back(temp-48);
			buffer.push_back(str_temp);
			str_temp.clear();
		}
	}
	vector<int>::iterator it;
	int num=0;
	for(it=count.begin(); it!=count.end(); ++it){
		int mul=*it;
		str_temp.clear();
		for(int k=0; k<mul; ++k){
			str_temp+=buffer[num];	
		}
		str_buffer+=str_temp;
		num++;
	}
	ret=&str_buffer;
	return *ret;
}

int main(){
	string input="a2b3c1d0";
	string ret;
	ret=Decode(input);
	cout<<ret<<endl;
return 0;
}
