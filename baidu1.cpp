#include<iostream>
using namespace std;
int main(){
    long long ch[13];
    ch[1]=1;
    for(int i=2;i<=12;i++){
        ch[i]=ch[i-1]*i;
    }
    char str[13];
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str+1);
        long long sum=0;
        for(int i=1;i<=12;i++){
            int k=0;
            for(int j=i+1;j<=12;j++){
                if(str[i]>str[j]) k++;
            }
            sum+=ch[12-i]*k;
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
