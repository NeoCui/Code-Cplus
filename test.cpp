#include <iostream>
#include <string>
#define MAX 7010
#define INF -65536
using namespace std;
int t[MAX][MAX];

bool flag[MAX] ;

int dis=INF, v;

int DFS(int sum, int pos, int n)
{
    if(sum>dis)
    {
        dis = sum ;
        v = pos;
    }
    flag[pos] = true ;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(t[pos][i] != 0 && !flag[i])
        {
            DFS(sum+t[pos][i],i,n);
        }
    }
}

void printstr(string prefix, string str){
	if(str.length()==0)
		cout<<prefix<<endl;
	else{
		for(int i=0; i<str.length(); ++i){
			printstr(prefix+str[i], str.substr(0,i)+str.substr(i+1,str.length()));
		}
	}
}

constexpr int get_five(){
	return 6;
}


int main()
{
	string input="abc";
	string prefix="";

	printstr(prefix,input);
	int some_value[get_five()+2]={1,2,3,4,5,6,7,8};
	for(int &x:some_value){
		cout<<x<<" ";
	}
	cout<<endl;
/*    int n;
    scanf("%d",&n) ;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int u , v , w ;
        scanf("%d%d%d",&u,&v,&w);
        t[u][v] = t[v][u] = w ;
    }
    
    DFS(0,1,n) ;
    
    dis = INF ;
    memset(flag,0,sizeof(flag)) ;
    DFS(0,v,n) ;
    
    cout<<dis*10+(1+dis)*dis/2<<endl;
*/
    return 0 ;
}
