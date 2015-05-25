#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N=1e6;
const int mod=1e9+7;
long long  s[N];//×¢Òâlong long 
void Init()
{
    s[0] = s[1] = 1;
    for (int i=2; i<=N; i++)
        s[i]=(s[i-1]+(i-1)*s[i-2])%mod;
}

int main()
{
		vector<int> n;
    Init();
    int T,t_n,cnt_T=1;
		int cnt=0;
		cin>>T;
		for(cnt=0;cnt<T;++cnt){
			cin>>t_n;
			n.push_back(t_n);
		}
		for(cnt_T=0;cnt_T<T;++cnt_T){
			t_n=n[cnt_T];
			cout<<"Case #"<<cnt_T+1<<":"<<endl;
			cout<<s[t_n]<<endl;
    }
    return 0;
}
