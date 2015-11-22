#include<iostream>
#include<string>
#include<unordered_map>


using namespace std;
typedef pair<char, int> si_Pair;

int is_include(string& a, string& b){
	if(a.empty()) return 0;
	unordered_map<char, int> hm;
	unordered_map<char, int>::iterator hm_iter;
	for(size_t i=0; i<a.length(); ++i){
		char cur=a.at(i);
		hm_iter=hm.find(cur);
		if(hm_iter!=hm.end()){
			hm.insert(si_Pair(cur,(hm_iter->second)+1));
		}else{
			hm.insert(si_Pair(cur,1));
		}
	}
	for(size_t i=0; i<b.length(); ++i){
		char cur=b.at(i);
		hm_iter=hm.find(cur);
		if(hm_iter==hm.end() || hm_iter->second==0)
			return 0;
		hm.insert(si_Pair(cur,(hm_iter->second)-1));
	}
	return 1;
}

int main(){

	string str1;
	string str2;
	cin>>str1>>str2;
	int ret;
	ret=is_include(str1, str2);
	cout<<ret<<endl;
	return 0;
}
