#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	ll k; cin >> k;
	ll n = 50;
	ll div = k/n;
	ll rem = k%n;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i){
		a[i] = n-1+ div - rem;
    }
    
    for(ll i = 0; i < rem; ++i){
		a[i] += n+1;
    }
	cout << n << endl;
	for(ll i = 0; i < n-1; ++i){
		cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    
    return 0;
}