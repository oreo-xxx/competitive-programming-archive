#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int V, E; cin >> V >> E;
    
    // initialization of Floyd-Warshall
    vector<vector<long long> > dp(V, vector<long long>(V, INF));
    for (int i = 0; i < V; ++i) dp[i][i] = 0;  // necessary
    
    // input
    for (int e = 0; e < E; ++e) {
        int a, b; cin >> a >> b;
        --a;--b;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }
    
    // Floyd-Warshall
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    
    // output
    for (int i = 0; i < V; ++i) {
      int ans = 0;
      for (int j = 0; j < V; ++j) {
        if(dp[i][j]==2) ++ans;
      }
      cout << ans << endl;
    }
}
