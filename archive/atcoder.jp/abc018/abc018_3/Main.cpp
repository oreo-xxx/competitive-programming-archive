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

vector<string> s;
vector<vector<int>> a;

int main(){
  int r,c,k;cin >> r >> c >> k;
  s.resize(r);
  a.resize(r);
  for(int i = 0; i < r; ++i){
    cin >> s[i];
    a[i].resize(c+1);
  }
  
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      if(s[i][j]!='x')continue;
      for(int m = i-k+1; m<i+k;++m){
        if(m<0||m>=r)continue;
        int rem = k-1-abs(m-i);
        int l = max(0,j-rem);
        int r = min(c,j+rem+1);
        ++a[m][l];
        --a[m][r];
      }
    }
  }
  for(int i = 0; i < r; ++i){
    for(int j = 0; j < c; ++j){
      a[i][j+1] += a[i][j];
    }
  }
  int ans = 0;
  for(int i = k-1; i <= r-k; ++i){
    for(int j = k-1; j <= c-k; ++j){
      if(a[i][j]==0)++ans;
    }
  }
  cout << ans << endl;
}
