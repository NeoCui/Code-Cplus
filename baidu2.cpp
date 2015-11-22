#include <iostream>
#include <string>

using namespace std;
#define MAX 10
#define INF 0

int t[MAX][MAX];
bool flag[MAX];
int dis=INF, v;

void DFS(int sum, int pos, int n)
{
    if(sum>dis)
    {
        dis = sum;
        v = pos;
    }
    flag[pos] = true;
    for(int i=1; i<=n; ++i)
    {
        if(t[pos][i]!=0 && !flag[i])
        {
            DFS(sum+t[pos][i],i,n);
        }
    }
}
int main()
{
    int T;
    cin>>T;
    int count=T;
    while(count--){
        int u, v, w;
        cin>>u>>v>>w;
        t[u][v] = t[v][u] = w;
    }
    
    DFS(0,1,T);
    
    dis = INF;
    memset(flag,0,sizeof(flag));
    DFS(0,v,T);
      
    int ret;
    ret=dis*10+(1+dis)*dis/2;
    cout<<ret<<endl;
    return 0 ;
}
