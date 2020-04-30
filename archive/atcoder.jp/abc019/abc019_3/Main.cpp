#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main() {
	ll  n;cin >>n;
	set<ll> se;
	for(int i = 0; i < n; ++i){
		ll a; cin >>a;
		while(true){
			if(a%2==0){a/=2;}
			else{break;}
        }
		se.insert(a);
    }
	ll ans=se.size();
    cout << ans << endl;
}
