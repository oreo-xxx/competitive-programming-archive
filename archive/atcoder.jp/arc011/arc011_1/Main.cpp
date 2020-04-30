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
  ll n, m, k;cin >>n>> m>> k;
  ll ans=0,rem=0;
  while(k>0){
    ans+=k;
    ll tmp = k/n;
    rem += k%n;
    tmp += rem/n;
    rem %= n;
    k=tmp*m;
  }
  cout << ans << endl;
}
