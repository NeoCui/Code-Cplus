#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
	int T=0, n=0;
	int cnt=0,cnt_T=0;
	double t_n=0;
	
	vector<int> input;
	vector<vector<double> > result;
	cin>>T;
	for(cnt=0; cnt<T; ++cnt){
		cin>>n;
		input.push_back(n);
	}
	result.resize(T);
	for(int i=0; i<T; ++i)
		result[i].resize(2);
	for(cnt_T=0; cnt_T<T; ++cnt_T){
		t_n=double(input[cnt_T]);
		result[cnt_T][0]=1+(t_n-2)*67/81;
		result[cnt_T][1]=(t_n+(67/81)*(t_n-2))/(1+(67/81)*(t_n-2));
//		result[cnt_T][1]=(46*t_n-38)/(19*t_n-11);
	}
	for(cnt_T=0; cnt_T<T; ++cnt_T){
		cout<<"Case #"<<cnt_T+1<<":"<<endl;
		cout<<fixed<<setprecision(6)<<result[cnt_T][0]<<' '<<result[cnt_T][1]<<endl;
	}	
	return 0;
}
