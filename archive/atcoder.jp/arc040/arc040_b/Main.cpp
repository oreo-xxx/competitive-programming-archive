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
  ll n,r;cin >> n>> r;
  string s; cin >> s;
  ll ans=0, d= 0;
  bool flag = false;
  for(ll i = n-1; i >= 0; --i){
    if(s[i]=='.'){
      if(!flag){
        d = max(d, i-r+1);
        flag = true;
      }
      i = i-r+1;
      ++ans;
    }
  }
  cout << ans + d << endl;
}
