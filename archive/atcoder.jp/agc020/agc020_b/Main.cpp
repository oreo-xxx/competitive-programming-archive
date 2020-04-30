#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<ll,  ll>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main() {
	ll  n;cin >>n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >>a[i];
    pint kouho={2, 2};
	for(int i = n-1; i >= 0; --i){
      ll gl=kouho.first, gr=kouho.second;
      ll nl=(gl+a[i]-1)/a[i];
      ll nr=gr/a[i];

      kouho={nl*a[i], nr*a[i]+a[i]-1};
      // cout << kouho.first << " " << kouho.second << endl;
      if(nl==0 || nr==0 || kouho.first >kouho.second){
        cout << -1 << endl;
        return 0;
      }
    }
    ll ans1 = kouho.first; 
    ll ans2= kouho.second;
	cout << ans1 << " " << ans2 << endl;
}
