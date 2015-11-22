#include<iostream>

using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int temp;
	bool isTrue=false;
	int input[M+1];
	for(int i=0; i<M+1; ++i){
		input[i]=0;
	}
	for(int i=0; i<N; ++i){
		cin>>temp;
		input[temp]++;
	}
	int i=0;
	for(i=0; i<M+1; ++i){
		if(input[i]>=(N/2)+1){
			cout<<i<<endl;
			isTrue=true;
			break;
		}
	}
	if(!isTrue)
		cout<<"?"<<endl;
return 0;
}
