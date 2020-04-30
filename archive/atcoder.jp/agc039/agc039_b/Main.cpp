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

bool dfs(const Graph &G, int v, int vdir, pint &num, vector<int> &dir) {
    bool res = true;
    dir[v] = vdir;
    if (vdir == 1) ++num.first;
    else if (vdir == -1) ++num.second;
    for (auto nv : G[v]) {
        if (dir[nv] == 0) {
            if (!dfs(G, nv, -vdir, num, dir)) res = false;
        }
        else if (dir[nv] != -vdir) res = false;
    }
    return res;
}

bool isbipartite(const Graph &G, vector<pint> &nums) {
    bool res = true;
    int N = (int)G.size();
    vector<int> dir(N, 0);
    for (int v = 0; v < N; ++v) {
        if (dir[v] != 0) continue;
        pint num = {0, 0};
        if (!dfs(G, v, 1, num, dir)) res = false;
        nums.push_back(num);
    }
    return res;
}

int main(){
    int n; cin >> n;
    int V = n;
    vector<vector<long long> > dp(V, vector<long long>(V, INF));
    for (int i = 0; i < V; ++i) dp[i][i] = 0;  // necessary
    Graph G(n);
    for(int i = 0; i < n; ++i){
      string s; cin >> s;
      for(int j = 0; j < n; ++j){
        if(s[j]=='1'){
          G[i].push_back(j);
          dp[i][j]=1;
        }
      }
    }
    vector<pint> tmp;
    ll ans = -1;
    if(!isbipartite(G,tmp)){
      cout << ans << endl;
      return  0;
    }
    // Floyd-Warshall
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      ans = max(ans,dp[i][j]);
    }
  }
  cout << ans+1 << endl;
}
