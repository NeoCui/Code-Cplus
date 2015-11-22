#include<iostream>

using namespace std;

char* itoa(int i) {
    int a,b,sign=0;
    char s[100]="";
    char *ret;
	ret=s;
    if((sign=i)<0){
        i=-i;
    }
	a=0;
    do{
		int temp=0;
		temp=i%10;
		cout<<temp<<endl;
        s[a++]=temp+'0';
		cout<<s[a]<<endl;
    }while((i/=10)>0);
    if(sign<0){
        s[a++]='-';
    }
    s[a]='\0';
    while(s[a--]!='\0'){
        *(ret++)=s[a];
    }
    *(ret++)='\0';
    return ret;
}
int main(){
	char* ret;
	ret=itoa(123);
	cout<<ret;
	return 0;
}
