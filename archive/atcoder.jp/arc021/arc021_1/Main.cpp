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
  int n = 4;
  Graph a(n);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int t;cin >> t;
      a[i].push_back(t);
    }
  }
  string ans = "GAMEOVER";
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n-1; ++j){
      if(a[i][j]==a[i][j+1]){
        ans = "CONTINUE";
      }
    }
  }
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < n; ++j){
      if(a[i][j]==a[i+1][j]){
        ans = "CONTINUE";
      }
    }
  }
  cout << ans << endl;
}
