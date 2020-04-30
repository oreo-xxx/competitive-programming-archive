#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> x(n);
    for(int i = 0; i < n; ++i){
    	cin >> x[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; ++i){
    	  ans += min( (x[i] - x[i-1])*a, b);
    }

    cout << ans << endl;
    return 0;
}