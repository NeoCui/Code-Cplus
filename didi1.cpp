#include<iostream>
#include<map>
#include<vector>

using namespace std;

int start=0;
int BucketSort(int* sum, int n)
{
    map<int, vector<int> >bucket;

    for(int i=0; i<n; ++i){
        bucket[sum[i]].push_back(i);
	}
    int maxInterval=0;
    for(map<int,vector<int> >::iterator iter=bucket.begin(); iter!=bucket.end(); ++iter)
    {
        int sizev = iter->second.size();
		if((iter->second[sizev-1]-iter->second[0])>maxInterval){
			start=iter->second[0]+1;
			maxInterval=iter->second[sizev-1]-iter->second[0];
		}
    }
    return maxInterval;
}

int subArraySum0(int A[], int n)
{
    if(n==0)
        return 0;
    int *sum = new int [n];

    sum[0] = A[0];
    for(int i=1; i<n; ++i)
        sum[i] = sum[i-1]+A[i];
    int ret = BucketSort(sum, n);
    delete []sum;
    return ret;
}

int main(){
	int num;
	int arr[1024];
	int i=0;
	char ch;
	while(cin>>num){
		arr[i++]=num;
		ch=getchar();
		if(ch=='\n') break;
	}
	int result;
	result=subArraySum0(arr,i);
	for(int i=start;i<start+result;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
