#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    ll n; cin >>n;
    ll ans = n * (n-1) /2;
    cout << ans << endl;
    return 0;
}