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
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];

  ll now = 1, ans = 0;
  for(int i = 0; i < n; ++i){
    ans += a[i]/now;
    ll tmp = a[i]%now;
    if(tmp==0) --ans, tmp=now;
    if(now == a[i]) ++now;
    if(i==0)now= 2;
    //cout << ans << " " << now << endl;
  }
  cout << ans << endl;
}
