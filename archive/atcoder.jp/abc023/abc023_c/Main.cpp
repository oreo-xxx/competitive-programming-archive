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
  ll r,c,k;cin >> r >> c >> k;
  ll n;cin >> n;
  vector<ll> col(c), row(r);
  vector<int> a(n),b(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i] >> b[i];
    --a[i];--b[i];
    ++row[a[i]];
    ++col[b[i]];
  }
  vector<ll> sumr(k+1), sumc(k+1);
  for(int i = 0; i < r; ++i){
    if(row[i]<=k) ++sumr[row[i]];
  }
  for(int i = 0; i < c; ++i){
    if(col[i]<=k) ++sumc[col[i]];
  }
  ll ans = 0;
  for(int i = 0; i <= k; ++i){
    ans += sumr[i] * sumc[k-i];
  }
  for(int i = 0; i < n; ++i){
    ll tmp = row[a[i]] + col[b[i]];
    if(tmp==k)--ans;
    if(tmp==k+1) ++ans;
  }
  cout << ans << endl;
}
