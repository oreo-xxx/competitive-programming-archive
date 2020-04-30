#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; cin >> n;
	vector<ll> a(n+1);
	for(int i = 0; i < n; ++i){
		cin >> a[i+1];
    }
    a.push_back(0);
    ll cost;
    for(int i = 0; i < n+1; ++i){
    	cost += abs(a[i+1]- a[i]);
    }
    for(int i = 0; i < n; ++i){
    	ll ans = cost;
        if((a[i+1]>a[i] && a[i+1] > a[i+2]) ||
            (a[i+1]<a[i] && a[i+1] < a[i+2])){
        	ans -= abs(a[i+1]-a[i]);
        	ans -= abs(a[i+2]-a[i+1]);
                ans += abs(a[i+2]-a[i]);
        }
        else{
        }
        cout << ans << endl;
    }
    return 0;
}