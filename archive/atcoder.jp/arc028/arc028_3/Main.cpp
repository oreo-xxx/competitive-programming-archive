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

Graph G;
vector<pint> ans;

int dfs(int s){
  int sum = 1,M = 0;
  for(auto u : G[s]){
    int tmp = dfs(u);
    M= max(M,tmp);
    sum+= tmp;
  }
  ans[s]={sum,M};
  return sum;
}

int main(){
  int n;cin >> n;
  G.resize(n);
  ans.resize(n);
  for(int i = 1; i < n; ++i){
    int a;cin >> a;
    G[a].push_back(i);
  }
  int sum = dfs(0);
  for(int i = 0; i < n; ++i){
    cout << max(ans[i].second , sum-ans[i].first) << endl;
  }
}
