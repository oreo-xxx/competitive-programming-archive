#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n, m;
	cin >>n >> m;
	vector<vector<int> > dp(n,  vector<int>(n, INF32));
    for (int i = 0; i <n; ++i) dp[i][i] = 0;  // necessary
    
    // input
    for (int e = 0; e < m; ++e) {
        int a, b, w; cin >> a >> b >> w;
        --a;--b;
        dp[a][b] = w;
        dp[b][a]=w;
    }
    
    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                
    int ans = INF32;              
    for(int i = 0; i < n; ++i){
        int tmp = 0;
        for(int j = 0; j < n; ++j){
              tmp = max(tmp, dp[i][j]);
        }
        ans = min(ans, tmp);
    }
	
	cout << ans << endl;
    return 0;
}
