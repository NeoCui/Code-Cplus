#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<sstream>

using namespace std;

int str2int(const string &str){
	stringstream ss(str);
	int num;
	if((ss>>num).fail()){
		cout<<"Error in converting string to int"<<endl;
	}
	return num;
}

int main(){
	int T=0, M=0, N=0;
	int cnt_ip=0, cnt_mask=0;
	int cnt_T=0;
	
	vector<vector<int> >::iterator ret;
	vector<vector<int> > I_ip;
	vector<vector<int> > I_mask;
	vector<vector<int> > V_temp;
	vector<vector<string> > ip;
	vector<vector<string> > mask;
	int result[50][50]={0};
	cin>>T;
	ip.resize(T);
	mask.resize(T);
	for(cnt_T=0; cnt_T<T; ++cnt_T){
		int cnt=0;
		cin>>N>>M;
		cin.get();
		ip[cnt_T].resize(N);
		mask[cnt_T].resize(M);
		ip[cnt_T].clear();
		mask[cnt_T].clear();
		string line;
		while(getline(cin,line)){
			ip[cnt_T].push_back(line);
			++cnt;
			if(cnt==N)
				break;
		}
		cnt=0;
		while(getline(cin,line)){
			mask[cnt_T].push_back(line);
			++cnt;
			if(cnt==M)
				break;
		}
	}
	for(cnt_T=0; cnt_T<T; ++cnt_T){
		N=ip[cnt_T].size();
		M=mask[cnt_T].size();
		I_ip.resize(N);
		I_mask.resize(M);
		V_temp.resize(N);
		for(int i=0;i<N;++i){
			V_temp[i].resize(4);
			I_ip[i].resize(4);
		}
		for(int i=0;i<M;++i){
			I_mask[i].resize(4);
		}
		int temp=0;
		for(cnt_ip=0; cnt_ip<N; ++cnt_ip){
			int pos=0;
			int t_pos=0;
			pos=ip[cnt_T][cnt_ip].find('.',pos);
			temp=str2int(ip[cnt_T][cnt_ip].substr(t_pos,pos));
			I_ip[cnt_ip][0]=temp;
			t_pos=pos+1;
			pos=ip[cnt_T][cnt_ip].find('.',t_pos);
			temp=str2int(ip[cnt_T][cnt_ip].substr(t_pos,pos));
			I_ip[cnt_ip][1]=temp;
			t_pos=pos+1;
			pos=ip[cnt_T][cnt_ip].find('.',t_pos);
			temp=str2int(ip[cnt_T][cnt_ip].substr(t_pos,pos));
			I_ip[cnt_ip][2]=temp;
			t_pos=pos+1;
			pos=ip[cnt_T][cnt_ip].length();
			temp=str2int(ip[cnt_T][cnt_ip].substr(t_pos,pos));
			I_ip[cnt_ip][3]=temp;
		}
		for(cnt_mask=0; cnt_mask<M; ++cnt_mask){
			int pos=0;
			int t_pos=0;
			pos=mask[cnt_T][cnt_mask].find('.',pos);
			temp=str2int(mask[cnt_T][cnt_mask].substr(t_pos,pos));
			I_mask[cnt_mask][0]=temp;
			t_pos=pos+1;
			pos=mask[cnt_T][cnt_mask].find('.',t_pos);
			temp=str2int(mask[cnt_T][cnt_mask].substr(t_pos,pos));
			I_mask[cnt_mask][1]=temp;
			t_pos=pos+1;
			pos=mask[cnt_T][cnt_mask].find('.',t_pos);
			temp=str2int(mask[cnt_T][cnt_mask].substr(t_pos,pos));
			I_mask[cnt_mask][2]=temp;
			t_pos=pos+1;
			pos=mask[cnt_T][cnt_mask].length();
			temp=str2int(mask[cnt_T][cnt_mask].substr(t_pos,pos));
			I_mask[cnt_mask][3]=temp;
		}
		for(int i=0; i<M; ++i){
			V_temp.resize(N);
			for(int k=0; k<N; ++k)
				V_temp[k].resize(4);
			for(int j=0; j<N; ++j){
				V_temp[j][0]=I_ip[j][0] & I_mask[i][0];
				V_temp[j][1]=I_ip[j][1] & I_mask[i][1];
				V_temp[j][2]=I_ip[j][2] & I_mask[i][2];
				V_temp[j][3]=I_ip[j][3] & I_mask[i][3];
			}
			sort(V_temp.begin(), V_temp.end());
			ret=unique(V_temp.begin(), V_temp.end());
			V_temp.erase(ret,V_temp.end());
			result[cnt_T][i]=V_temp.size();
		}
	}
	for(cnt_T=0; cnt_T<T; ++cnt_T){
		cout<<"Case #"<<cnt_T+1<<":"<<endl;
		for(int i=0;i<mask[cnt_T].size();++i)
			cout<<result[cnt_T][i]<<endl;
	}
	return 0;
}
