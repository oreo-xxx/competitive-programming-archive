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
  int n,m;cin >> n >> m;
  vector<vector<int>> a(n+2,vector<int>(m+2));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      char c; cin >> c;
      a[i+1][j+1] = c - '0';
    }
  }
  
  vector<vector<int>> ans(n,vector<int>(m));
  for(int i = 0; i < n; ++i){  
    for(int j = 0; j < m; ++j){ 
      int tmp = a[i][j+1];
      tmp = min(tmp,a[i+1][j+2]);
      tmp = min(tmp,a[i+2][j+1]);
      tmp = min(tmp,a[i+1][j]);
      ans[i][j]= tmp;
      
      a[i][j+1]  -= tmp;
      a[i+1][j+2]-= tmp;
      a[i+2][j+1]-= tmp;
      a[i+1][j]  -= tmp;
    }
  }
  
  for(int i = 0; i < n; ++i){  
    for(int j = 0; j < m; ++j){ 
      int tmp = a[i][j+1];
      tmp = min(tmp,a[i+1][j+2]);
      tmp = min(tmp,a[i+2][j+1]);
      tmp = min(tmp,a[i+1][j]);
      ans[i][j]+= tmp;
    }
  }
  
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){ 
      cout << ans[i][j];
    }
    cout << endl;
  }
}
