#include<iostream>

using namespace std;
const int MAX=10005;
struct Node{
    int x,h;
};
Node a[MAX];

int main()
{
    int count;
    while(cin>>count){
        for(int i=0;i<count;i++){
            cin>>a[i].x>>a[i].h;
        }
        int res=1;
        Node previous=a[0];
        for(int i=1;i<count;i++){
            if((a[i].x+a[i].h)<=(previous.x+previous.h)){
                previous=a[i];
            }
            else if(a[i].x>=(previous.x+previous.h)){
                res++;
                previous=a[i];
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
