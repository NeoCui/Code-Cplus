#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main(){
	vector<vector<int> > array;
	int row=0;
	int num=0;
	char ch;
	while(cin>>num){
		array.resize(row+1);
		array[row].push_back(num);
		ch=getchar();
		if(ch==';')
			row++;
		if(ch=='\n')
			break;
	}
	int col=array[0].size()-1;
	int maxsum=0;
	cout<<"row:"<<row+1<<endl;
	cout<<"col:"<<col+1<<endl;
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j){
			cout<<"current maxsum:"<<maxsum<<endl;
			maxsum=max(array[i][j]+array[i][j+1]+array[i+1][j]+array[i+1][j+1], maxsum);
		}
	}
	cout<<"Max: "<<maxsum<<endl;

	return 0;
}
