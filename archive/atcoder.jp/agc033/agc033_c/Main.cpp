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

struct Diameter {
    vector<int> prev;
    pair<int,int> DiameterDFS(const Graph &G, int v, int p) {
        pair<int,int> res(v, 0);
        for (int i = 0; i < (int)G[v].size(); ++i) {
            if (G[v][i] == p) continue;
            pair<int,int> tmp = DiameterDFS(G, G[v][i], v);
            tmp.second++;
            if (tmp.second > res.second) res = tmp, prev[G[v][i]] = v;
        }
        return res;
    }

    vector<int> solve(const vector<vector<int> > &G) {
        prev.assign((int)G.size(), -1);
        pair<int,int> leaf = DiameterDFS(G, 0, -1);
        prev.assign((int)G.size(), -1);
        pair<int,int> t = DiameterDFS(G, leaf.first, -1);
        vector<int> res;
        int cur = t.first;
        while (cur != -1) res.push_back(cur), cur = prev[cur];
        return res;
    }
};


int main(){
  int n;cin >> n;
  Graph G(n);
  for(int i = 0; i < n-1; ++i){
    int a,b;cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  Diameter di;
  auto v = di.solve(G);
  string ans = "First";
  if(v.size()%3 == 2){
    ans = "Second";
  }
  cout << ans << endl;
}
