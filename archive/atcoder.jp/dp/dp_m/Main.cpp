#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll dp[110][101010];
ll sum[101010];
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){cin >> a[i];} 
	
	dp[0][0]=1;
	for(int i = 1; i <= n; ++i){
		sum[0]=0;
		for(int j = 0; j<= k; ++j){
			sum[j+1] = (sum[j]+dp[i-1][j]) % MOD;
        }
		for(int j =0; j <= k; ++j){
	        dp[i][j] += (sum[j+1] - sum[max(0, j-a[i-1])] + MOD)% MOD;
       }
    }
    
    cout << dp[n][k] << endl;
}