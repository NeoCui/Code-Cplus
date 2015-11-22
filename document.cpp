#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void Swap(vector<int>& v, int k, int j){
	int temp;
	temp = v[k];
	v[k] = v[j];
	v[j] = temp;
}
void Qsort(vector<int>& data, int left, int right){
	int j, last;
	if(left >= right)
		return;
	Swap(data, left, (left+right)/2);
	last = left;
	for(j=left+1; j<right; ++j){
		if(data[j]<data[left])
			Swap(data,++last,j);
	}
	Swap(data,left,last);
	Qsort(data,left,last-1);
	Qsort(data,last+1,right);
}

int main(int argc, char** argv){
	vector<int> data;
	ifstream in("./document.txt");
	if(!in){
		cout<<"File error!"<<endl;
		exit(1);
	}
	int temp;
	while(!in.eof()){
		in>>temp;
		data.push_back(temp);
	}
	in.close();
	int n;
	n=data.size();
	cout<<n<<endl;
	Qsort(data,0,n-1);
	ofstream out("./document.txt");
	if(!out){
		cout<<"File error."<<endl;
		exit(1);
	}
	for(size_t i=0;i<data.size();++i){
		out<<data[i]<<" ";
	}
	out.close();
	return 0;
}
