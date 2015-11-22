#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<vector<int> > process;
	process.resize(N);
	int S,C;
	for(int i=0; i<N; ++i){
		cin>>S>>C;
		process[i].push_back(S);
		process[i].push_back(C);
	}
	for(int i=0; i<N; ++i){
		cout<<process[i][0]<<"/"<<process[i][1]<<endl;
	}
return 0;
}
