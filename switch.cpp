#include<iostream>

using namespace std;

int main(){
	int n=0;
	while(n<5){
		switch(n){
			case 0:
			case 1:n=n+2;
			case 2:n=n+3;
			case 3:
			case 4:
			default: n=n+5;
		}
	}
	cout<<"n:"<<n<<endl;
}
