#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int GRID_SIZE=8;

bool check_Valid(int* arr, int row, int col){
	for(int row_temp=0; row_temp<row; ++row_temp){
		int col_temp=*(arr+row_temp);
		if(col_temp==col){
			return false;
		}
		int col_distance=abs(col-col_temp);
		int row_distance=row-row_temp;
		if(col_distance==row_distance){
			return false;
		}
	}
	return true;
}

void place_Queen(int row, int* arr, vector<int>& ret){
	if(row==GRID_SIZE){
		for(int i=0; i<8; ++i){
			ret.push_back(*(arr+i));
		}
		return;
	}else{
		for(int col=0; col<GRID_SIZE; ++col){
			if(check_Valid(arr,row,col)){
				*(arr+row)=col;
				place_Queen(row+1, arr, ret);
			}
		}
	}
}

int main(){
	vector<int> result;
	int array[8]={0};
	place_Queen(0, array, result);
	vector<int>::iterator it;
	int count=0;
	for(it=result.begin(); it!=result.end(); ++it){
		count++;
		cout<<*it<<" ";
		if(count%7==0)
			cout<<endl;
	}
return 0;
}
