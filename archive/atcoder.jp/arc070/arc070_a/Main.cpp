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
  ll a;cin >> a;
  ll ans = 0;
  for(int i = 0; i <= a; ++i){
    if(i*(i+1)>=2*a){
      ans=i;
      break;
    }
  }
  cout << ans << endl;
}
