#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<pll> calc_divisor(long long n) {
    vector<pll> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back({i, n/i});
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
	ll n;
	cin >> n;
  auto a=calc_divisor(n);
  ll ans = INF;
  for(int i = 0; i < a.size(); ++i){
    ll k1 = to_string(a[i].first).size();
    ll k2 = to_string(a[i].second).size();
    ll tmp = max(k1, k2);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}

