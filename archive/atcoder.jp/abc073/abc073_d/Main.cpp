#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	ll n, m, r; cin >>n>> m>> r;
	
	vector<int> root(r);
	for(int i = 0; i < r; ++i){cin >> root[i]; --root[i];}
	sort(root.begin(), root.end ());
	
	vector<vector<long long> > dp(n, vector<long long>(n, INF64));
    for (int i = 0; i<n; ++i) dp[i][i] = 0;
    
    // input
    for (int i = 0; i < m; ++i) {
        ll a, b, w; cin >> a >> b >> w;
        --a; --b;
        dp[a][b] = w; dp[b][a] = w;
    }
    
    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    ll ans = INF64;
    do {
    	ll tmp = 0;
         for(int i = 0; i < r-1; ++i){
         	tmp += dp[root[i]][root[i+1]];
         }
         ans = min(ans, tmp);
    } while( next_permutation(root.begin(), root.end()) );
    cout << ans << endl;
    return 0;
}