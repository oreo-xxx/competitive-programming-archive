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

ll n,m;
vector<ll> a, sum;

bool check(ll mb){
  ll num = 0;
  for(int i = 0; i < n; ++i){
    ll idx = lower_bound(a.begin(), a.end(), mb-a[i])-a.begin();
    num += n-idx;
  }
  if(num>=m)return true;
  return false;
}

int main(){
  cin >> n >> m;
  a.resize(n);
  sum.resize(n+1);
  for(int i = 0; i < n; ++i)cin >> a[i];
  sort(a.begin(), a.end());
  for(int i = 0; i < n; ++i)sum[i+1]=sum[i]+a[i];
  ll lb = 0, ub = INF;
  while(ub-lb>1){
    ll mb = (ub+lb)/2;
    if(check(mb))lb = mb;
    else ub = mb;
  }
  
  ll ans = 0, num = 0;
  for(int i = 0; i < n; ++i){
    ll idx = lower_bound(a.begin(),a.end(),lb-a[i])-a.begin();
    num += n-idx;
    ans+= a[i]* (n-idx);
    ans += sum[n]- sum[idx];
  }
  ans -= (num-m)*lb;
  cout << ans << endl;
}
