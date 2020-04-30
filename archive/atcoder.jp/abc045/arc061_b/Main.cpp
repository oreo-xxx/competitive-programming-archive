#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	ll h, w, n; cin >> h >> w >> n;
	map<P, ll> mp;
	for(int i = 0; i < n; ++i){
		ll a, b; cin >>a >> b;
		--a; --b;
		for(ll j = -2; j <=0 ; ++j){
			for(ll k = -2; k <=0; ++k){
				if(j+a<0 ||j+a+2>=h || k+b<0 || k+b+2>=w){continue;}
				++mp[{j+a, k+b}];
            }
        }
    }
    vector<ll> a(10);
    ll count=0;
    for(auto it : mp){
    	++a[it.second];
        ++count;
    }
    a[0]=((h-2)*(w-2)-count);
    
    for(int i = 0; i < 10; ++i){
    	cout << a[i] << endl;
    }
    
    return 0;
}