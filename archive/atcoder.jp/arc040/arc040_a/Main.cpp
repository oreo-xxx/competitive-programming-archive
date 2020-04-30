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
  int n; cin >> n;
  map<char,int> mp;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      char c; cin >> c;
      ++mp[c];
    }
  }
  string ans = "DRAW";
  if(mp['R']>mp['B'])ans="TAKAHASHI";
  if(mp['R']<mp['B'])ans = "AOKI";
  cout << ans << endl;
}
