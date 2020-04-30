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

int n,k;
bool flag = false;

void dfs(int i, Graph& G, vector<int>& buf){
  if(i==n){
    int tmp = 0;
    for(int j = 0; j < n; ++j){
      tmp ^= buf[j];
    }
    if(tmp==0){
      flag = true;
    }
  }
  else{
    for(int j = 0; j < k; ++j){
      buf[i] = G[i][j];
      dfs(i+1, G, buf);
    }
  }
}

int main(){
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(k));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < k; ++j){
      cin >> a[i][j];
    }
  }
  vector<int> buf(n);
  dfs(0, a, buf);
  string ans = "Nothing";
  if(flag)ans = "Found";
  cout << ans << endl;
}
