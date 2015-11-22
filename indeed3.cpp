#include<iostream>
#include<vector>

using namespace std;

void Qsort(vector<int>& data, int start, int end){
	if(start>=end){
		return;
	}
	int key=data[start];
	int low=start;
	int high=end;
	while(low<high){
		while(low<high && key<=data[high]){
			high--;
		}
		data[low]=data[high];
		while(low<high && key>=data[low]){
			low++;
		}
		data[high]=data[low];
	}
	data[low]=key;
	Qsort(data,start,low-1);
	Qsort(data,low+1,end);
}

int main(){
	int N,M;
	cin>>N>>M;
	int temp;
	bool isTrue=true;
	vector<int> A;
	vector<int> B;
	for(int i=0; i<N; ++i){
		cin>>temp;
		A.push_back(temp);
	}
	for(int i=0; i<M; ++i){
		cin>>temp;
		B.push_back(temp);
	}
	if(M>N){
		isTrue=false;
	}else{
		Qsort(A,0,N-1);
		Qsort(B,0,M-1);
/*		for(int i=0;i<N;++i){
			cout<<A.at(i)<<"/";
		}
		cout<<endl;
		for(int i=0;i<M;++i){
			cout<<B.at(i)<<"/";
		}
		cout<<endl;*/
		for(int i=M-1; i>=0; --i){
			if(A.at(N-M+i)<B.at(i)){
				isTrue=false;
				break;
			}
		}
	}
	if(!isTrue){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
return 0;
}
