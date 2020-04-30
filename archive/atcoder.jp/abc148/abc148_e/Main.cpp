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
  ll n;cin >>n;
  if(n%2==1){
    cout << 0 << endl;
    return 0;
  }
  ll k =10;
  ll ans = n/k;
  while(n>k){
    k*=5;
    ans+=n/k;
  }
  cout << ans << endl;
}
