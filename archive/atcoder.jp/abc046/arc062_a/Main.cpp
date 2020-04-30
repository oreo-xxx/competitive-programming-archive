#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    return a / g * b;
}

int main(){
	ll n; cin >> n;
	vector<ll> t(n), a(n);
	for(int i = 0; i < n; ++i){
		cin >> t[i] >> a[i];
    }
    ll l=1, r=1;
    for(int i = 0; i < n; ++i){
      ll j1=l/t[i];
      if(l% t[i]!=0)++j1;
     ll j2 = r/a[i];
     if(r%a[i]!=0){++j2;}
     ll j =max(j1, j2);
      {l=t[i]*j;r=a[i]*j;}
      // cout << l <<" " << r << endl;
    }
    cout << l+r << endl;
}