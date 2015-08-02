#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

void Demo_Set(){
	set<string> strset;
	set<string>::iterator si;
	strset.insert("1");
	strset.insert("2");
	strset.insert("3");
	strset.insert("4");
	for(si=strset.begin(); si!=strset.end(); ++si){
		cout<<*si<<" ";
	}
	cout<<endl;
}

//changed the input to be vector
inline void swap(vector<int>& v, int k, int j){
	int temp;
	temp = v[k];
	v[k] = v[j];
	v[j] = temp;
}
void Qsort(vector<int>& v, int left, int right){
	int j, last;
	if(left>=right){
		return;
	}
	swap(v, left, (left+right)/2);
	last = left;
	for(j = left+1; j<right; ++j){
		if(v[j]<v[left]){
			swap(v, ++last, j);
		}
	}
	swap(v, left, last);
	Qsort(v, left, last);
	Qsort(v, last+1, right);
}
//Shell Sort
void ShellPass(vector<int>& array, const int& n, const int& d){
	int temp;
	for(int i=d; i<n; ++i){
		if(array[i]<array[i-d]){
			temp=array[i];
			int j = i-d;
			do{
				array[j+d] = array[j];
				j = j-d;
			}while(j>=0 && temp<array[j]);
			array[j+d] = temp;
		}
	}
}

void ShellSort(vector<int>& array, const int& n){
	int d = n;
	do{
		d = d/2;
		ShellPass(array, n, d);
	}while(d>1);
}

//Heap Sort(Build Heap() and Heapify() undefined)
void Heapify(vector<int>& R, int i, int len){
	int temp = R[i];
	int left = 2*i+1;
	int right = left+1;
	for(int max=left; max<len; max=2*max+1){
		if(max!=len-1 && R[max+1]>R[max]){
			++max;
		}
		if(temp<R[max]){
			R[i] = R[max];
			i = max;
		}else{
			break;
		}
	}
	R[i] = temp;
}
void BuildHeap(vector<int>& R, int len){
	for(int i=len/2-1; i>=0; --i){
		Heapify(R, i, len);
	}
}

void HeapSort(vector<int>& R, int n){
	int i;
	BuildHeap(R, n);
	int temp = 0;
	for(i=n-1; i>0; --i){
		temp = R[0];
		R[0] = R[i];
		R[i] = temp;
		Heapify(R, 0, i);
	}
}


int main(int argc, char** argv){
	cout<<"Enter the number you want to sort:";
	int n;
	cin>>n;
	default_random_engine rd(time(0));
	uniform_int_distribution<unsigned> u(0,100);
	//Quick Sort
	cout<<"Quick Sort:"<<endl;
	vector<int> arr;
	for(int j=0; j<n; ++j){
		arr.push_back(u(rd));
	}
	for(int j=0; j<n;++j){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
	Qsort(arr, 0, n);
	for(int j=0; j<n;++j){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
	//Shell Sort
	cout<<"Shell Sorti:"<<endl;
	vector<int> data;
	vector<int>::iterator iter;
	for(int j=0; j<n; ++j){
		data.push_back(u(rd));
	}
	for(iter=data.begin(); iter!=data.end(); ++iter){
		cout<<*iter<<" ";
	}
	cout<<endl;
	ShellSort(data, n);
	for(iter=data.begin(); iter!=data.end(); ++iter){
		cout<<*iter<<" ";
	}
	cout<<endl;
	//Heap Sort
	cout<<"Heap Sort:"<<endl;
	vector<int> hdata;
	vector<int>::iterator hiter;
	for(int j=0; j<n; ++j){
		hdata.push_back(u(rd));
	}
	for(hiter=hdata.begin(); hiter!=hdata.end(); ++hiter){
		cout<<*hiter<<" ";
	}
	cout<<endl;
	HeapSort(hdata, n);
	for(hiter=hdata.begin(); hiter!=hdata.end(); ++hiter){
		cout<<*hiter<<" ";
	}
	cout<<endl;

	//Set
	cout<<"Use of 'Set':"<<endl;
	Demo_Set();
	return 0;
}
