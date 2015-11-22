#include<iostream>
#include<vector>

using namespace std;

int dp[100];
int lis=0;
void LIS(vector<int>& arr, int size){
	for(int i=0; i<size;++i){
		dp[i]=1;
		for(int j=0; j<i; ++j){
			if(arr[i]>arr[j] && dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				if(dp[i]>lis){
					lis=dp[i];
				}
			}
		}
	}
}

void outputLIS(vector<int>& arr, int index){
	bool isLIS=false;
	if(index<0 || lis==0){
		return;
	}
	if(dp[index]==lis){
		--lis;
		isLIS=true;
	}
	outputLIS(arr, --index);
	if(isLIS){
		cout<<arr[index+1]<<" ";
	}
}

int main(){
	int num;
	char ch;
	vector<int> input;
	while(cin>>num){
		input.push_back(num);
		ch=getchar();
		if(ch=='\n')
			break;
	}
	LIS(input, input.size());
	outputLIS(input, input.size()-1);
	cout<<endl;
return 0;
}
