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
  ll n;cin >> n;
  ll sum = 0, M = 0;
  for(int i = 0; i < n; ++i){ 
    ll a;cin >> a;
    sum += a;
    M = max(M,a);
  }
  cout << sum << endl;
  if(n == 1){
    cout << sum << endl;
  }
  else{
    ll res = sum - M;
    cout << max(M-res, 0LL) << endl;
  }
}
