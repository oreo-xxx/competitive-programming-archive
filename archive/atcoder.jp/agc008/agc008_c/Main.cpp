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
  ll i,o,t,j,l,s,z;
  cin >>i>> o>> t>> j>> l>> s>> z;
  ll ans =o;
  if(i%2+j%2+l%2>1){
    ll tmp = min(1LL, min(i, min(j, l)));
    ans+=3*tmp;
    i-=tmp;j-=tmp;l-=tmp;
  }
  ans+=(i/2)* 2;
  ans+=(j/2)* 2;
  ans+=(l/2)* 2;
  cout << ans << endl;
}
