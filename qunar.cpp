#include<iostream>
#include<vector>

using namespace std;

int main(){
	int temp;
	int temp_T;
	vector<int> output;
	vector<vector<int> > input(3);
	vector<int> T;
	for(int i=0; i<3; ++i){
		cin>>temp_T;
		T.push_back(temp_T);
//		input[i].resize(temp_T);
		while(temp_T--){
			cin>>temp;
			input[i].push_back(temp);
		}
	}
	temp=0;
	for(int i=0; i<2; ++i){
		if(T[i]>=T[i+1]){
			temp++;
		}
	}
	int a,b;
	if(temp==0){
		a=1;
		b=2;
	}
	if(temp==1){
		a=0;
		b=2;
	}
	if(temp==2){
		a=0;
		b=1;
	}
	bool flag=false;
	for(int i=0; i<T[temp]; ++i){
		for(int j=0; j<T[a]; ++j){
			if(input[temp][i]==input[a][j]){
				temp_T=input[temp][i];
				flag=true;
				break;
			}
			flag=false;	
		}
		if(flag){
			for(int k=0; k<T[b]; ++k){
				if(input[b][k]==temp_T){
					output.push_back(temp_T);
					break;
				}
			}
		}
	}
	if(output.empty())
		return 0;
	sort(output.begin(),output.end());
	vector<int>::iterator it=output.begin();
	for(;it<output.end()-1;++it){
		cout<<*it<<" ";
	}
	cout<<*it<<endl;
	return 0;
}
