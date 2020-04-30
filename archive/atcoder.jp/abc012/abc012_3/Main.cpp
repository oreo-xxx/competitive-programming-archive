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

vector<pll> calc_divisor(long long n) {
    vector<pll> res;
    for (long long i = 1LL; i <= n; ++i) {
        if (n % i == 0) {
            res.push_back({i, n/i});
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
  ll n;cin >>n;
  n = 2025-n;
  auto a=calc_divisor(n);
  for(auto p : a){
    ll l = p.first;
    ll r = p.second;
    if(9<l || 9<r)continue;
    cout << l << " x " << r << endl;
  }
}
