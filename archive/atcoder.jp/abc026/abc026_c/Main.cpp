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

int n;

ll dfs(int cur, Graph& G){
  int s = G[cur].size();
  if(s==0) return 1;
  ll m = INF;
  ll M = 0;
  for(int i = 0; i < s; ++i){
    ll ret = dfs(G[cur][i], G);
    m = min(m, ret);
    M = max(M, ret);
  }
  return m + M + 1;
}

int main(){
  cin >> n;
  Graph G(n);
  for(int i = 0; i < n-1; ++i){
    int a;cin >> a;
    --a;
    G[a].push_back(i+1);
  }
  cout << dfs(0,G) << endl;
}
