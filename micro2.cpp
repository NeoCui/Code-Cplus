#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MaxSize=10000;

int arr[MaxSize][MaxSize];
int dis[MaxSize][MaxSize];
bool flag[MaxSize][MaxSize]={false};

int city=0;
int oper=0;

void Init()
{
	int u,v,k;
	cin>>city>>oper;
	for(int i=0;i<city-1;++i){
		cin>>u>>v>>k;
		arr[u-1][v-1]=k;
		arr[v-1][u-1]=k;	
		flag[u-1][v-1]=true;
		flag[v-1][u-1]=true;
	}
}

int Path()
{
	int sum=0;
	for(int i=0;i<city;++i){
		for(int j=0;j<city;++j){
			dis[i][j]=arr[i][j];
		}
	}

	for(int k=0;k<city;++k){
		for(int i=0;i<city;++i){
			for(int j=i+1;j<city;++j){
				if(dis[i][j]==0 && (k!=i) &&(k!=j))
					dis[i][j]=dis[i][k]+dis[k][j];
				if(!flag[i][j] && dis[i][k]+dis[k][j]<dis[i][j] && (j!=k) && (i!=k)){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int i=0; i<city; ++i){
		for(int j=i+1; j<city; ++j){
			sum+=dis[i][j];
		}
	}
	return sum;
}

int main()
{
	vector<int> ret;
	string temp;
	int u,v,k;
	int result;
	Init();
	while(oper--){
		cin>>temp;
		if(temp=="QUERY"){
			result=Path();
			ret.push_back(result);
		}
		else{
			cin>>u>>v>>k;
			arr[u-1][v-1]=k;
			arr[v-1][u-1]=k;
			flag[u-1][v-1]=false;
			flag[v-1][u-1]=false;
		}
	}
	vector<int>::iterator it;
	it=ret.begin();
	while(it!=ret.end()){
		cout<<*it<<endl;
		it++;
	}
	return 0;
}
