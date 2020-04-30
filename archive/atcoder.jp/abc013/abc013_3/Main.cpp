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

ll n,h,a,b,c,d,e;

ll check(int i){
  ll rem = n-i;
  ll lb = -1, ub = rem;
  while(ub - lb > 1){
    ll mb = (lb+ub)/2LL;
    if(h + mb*d - (rem-mb)*e > 0){
      ub = mb;
    }
    else{
      lb = mb;
    }
  }
  return c*ub;
}

int main(){
  cin >> n >> h >> a >> b >> c >> d >> e;
  ll bh = d, bc = c;
  if(b*c>d*a)bh = b, bc = a;
  ll ans = INF;
  ll tmp = 0;
  for(int i = 0; i < n; ++i){
    ans = min(ans, tmp+check(i));
    tmp += a;
    h += b;
  }
  if(ans == INF) ans = 0;
  cout << ans << endl;
}
