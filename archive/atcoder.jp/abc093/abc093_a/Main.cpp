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
  string s;cin >> s;
  bool fa=false, fb = false, fc = false;
  for(int i = 0; i < 3; ++i){
    if(s[i]=='a')fa= true;
    if(s[i]=='b')fb= true;
    if(s[i]=='c')fc= true;
  }
  string ans = "No";
  if(fa&&fb&&fc)ans = "Yes";
  cout << ans << endl;
}
