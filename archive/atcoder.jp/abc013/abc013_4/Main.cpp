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

unordered_map<int, int> G;
vector<int> a;

int main(){
  int n,m,d;
  cin >> n >> m >> d;
  a.resize(n);
  iota(a.begin(),a.end(),0);
  for(int i = 0; i < m; ++i){
    int j;cin >> j;
    swap(a[j-1], a[j]);
  }
  for(int i = 0; i < n; ++i)G[a[i]]=i;
  
  int ln = log2(d);
  vector<vector<int>> next(ln+1,vector<int> (n));
  for(int i = 0; i < n; ++i){
    next[0][i]= G[i];
  }
  for(int i = 0; i < ln; ++i){
    for(int j = 0; j < n; ++j){
      next[i+1][j]=next[i][next[i][j]];
    }
  }
  for(int i = 0; i < n; ++i){
    int ans= i;
    for(int j = 0; j <= ln; ++j){
      if((d>>j)&1) ans = next[j][ans];
    }
    cout << ans+1 << endl;
  }
}
