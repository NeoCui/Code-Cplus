#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int isprime[200];

int main()
{
	for (int i = 1; i < 200 ;i++)
		isprime[i] = 1;
	for (int i = 2; i < 200; i++) {
		if (isprime[i] == 0)
			continue;
		for (int j = i * 2; j < 200; j+=i)
			isprime[j] = 0;
	}
	for(int i=0; i<200;++i){
		cout<<isprime[i]<<"/";
	}
	cout<<endl;
	int T;
	cin>>T;
	for (int testcase = 1; testcase <= T; testcase++)
	{
		cout<<"Case #"<<testcase<<": ";
		long long n, backup;
		cin>>n;
		backup = n;
		vector<long long> factors;
		for (long long i = 2; i <= n/i; i++) {
			if (n%i) continue;
			long long cur = 1;
			while(n % i == 0) {
				n /= i;
				cur *= i;
			}
			factors.push_back(cur);
		}
		if (n > 1) {
			factors.push_back(n);
			n = 1;
		}
		vector<int> dp(1<<factors.size());
		for (int i = 0; i < (1<<factors.size()); i++) {
			long long curnum = 1;
			for (int j = 0; j < factors.size(); j++) {
				if (i & (1<<j)) {
					curnum *= factors[j];
				}
			}
			int digitsum = 0;
			while(curnum) {
				digitsum += curnum % 10;
				curnum /= 10;
			}
			if (isprime[digitsum]) {
				dp[i] = 0; // lose position
			} else {
				dp[i] = 0;
				for (int j = 0; j < factors.size(); j++) {
					if (i & (1<<j)) {
						if (dp[i^(1<<j)] == 0) {
							dp[i] = 1;
							break;
						}
					}
				}
			}
		}
		if(dp.back()){
			cout<<"Laurence"<<endl;
		}else{
			cout<<"Seymour"<<endl;
		}
//		puts(!dp.back() ? "Seymour" : "Laurence");
	}
	return 0;
}
