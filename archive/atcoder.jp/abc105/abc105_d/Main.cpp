#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,m; cin >>n >> m;
    vector<ll> a(n);
    vector<ll> s(n+1);
    map<ll, ll> mp;
    for(int i = 0; i < n; ++i){
    	  cin >> a[i];
    }
    ++mp[0];
    for(int i = 0; i < n; ++i){
    	  s[i+1] = s[i]+a[i];
          s[i+1]%= m;
          ++mp[s[i+1]];
    }
    ll ans = 0;
    for(auto itr : mp){
    	  ans += itr.second * (itr.second-1) /2;     
    }
    cout << ans << endl;
    return 0;
}