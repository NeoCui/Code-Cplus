#include <iostream>
#include<cmath>
using namespace std;

int Bear_Apple(int N){
	int ret;
	ret=N*(pow(N,N-1)-1)+1;
	return ret;
}

int main() {
	cout<<"How many bears:";
	int N;
	cin>>N;
	cout<<Bear_Apple(N)<<endl;

/*    int a[6][6];
    while (cin >> a[0][0]) {
        for(int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (i != 0 || j != 0)
                    cin >> a[i][j];
                if (i == 0 && j != 0) 
                    a[i][j] += a[i][j-1];
                if (i != 0 && j == 0) 
                    a[i][j] += a[i-1][j];
                if (i != 0 && j != 0) 
                    a[i][j] += (a[i-1][j] > a[i][j-1]) ? 
                        a[i-1][j] : a[i][j-1];
            }
        }
        cout << a[5][5] << endl;
    }
*/
    return 0;
}
