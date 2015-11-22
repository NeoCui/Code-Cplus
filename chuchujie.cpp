#include<iostream>

using namespace std;

#define VexNum 100
#define INF 65530

int Floy(int (*A)[VexNum], int vex){
    int i,j,k;
    int sum=0;
	for(k=0; k<vex; ++k){
    	for(i=0; i<vex; ++i){
        	for(j=0; j<vex; ++j){
            	if(*(*(A+i)+j)>*(*(A+i)+k)+*(*(A+k)+j)){
               		*(*(A+i)+j)=*(*(A+i)+k)+*(*(A+k)+j);
                	sum=*(*(A+i)+j);
            	}
        	}
    	}
	}
	return sum;
}

int main(){
    int ret=0;
    int N,M;
    int girl[VexNum];
    int A[VexNum][VexNum];
    cin>>N>>M;
    int temp;
    for(int n=0; n<N; ++n){
        cin>>temp;
        girl[n]=temp;
    }
	for(int m=0; m<M; ++m){
        for(int m1=0; m1<M; ++m1){
        	A[m][m1]=INF;
        }
    }    
    int no1,no2;
    for(int m2=0; m2<M; ++m2){
        cin>>no1>>no2;
        A[no1-1][no2-1]=girl[no2-1];
        A[no2-1][no1-1]=girl[no2-1];
    }
	for(int m=0; m<M; ++m){
        for(int m1=0; m1<M; ++m1){
        	cout<<A[m][m1]<<" ";
        }
		cout<<endl;
	}
    ret=Floy(A, M);
	cout<<ret<<endl;
    return 0;
}
