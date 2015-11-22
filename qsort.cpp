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

int main(int argc, char** argv){
	int a[10]={2,3,1,6,5,4,9,10,4,7};
	vector<int> data(a,a+10);
	int end=data.size();
	Qsort(data,0,end-1);
	vector<int>::iterator it;
	for(it=data.begin();it<data.end();++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}
