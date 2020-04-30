#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n,m;cin >> n>> m;
  graph G(n);
  for(int i = 0; i < m; ++i){ 
    int a,b;cin >> a>> b;
    G[a].push_back(b);
  }
  string ans="IMPOSSIBLE";
  for(int i = 0; i < G[1].size(); ++i){
    int p = G[1][i];
    for(int j = 0; j < G[p].size(); ++j){
      if(G[p][j]==n)ans="POSSIBLE";
    }
  }
  cout << ans << endl;
}
