#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<P> prime_factorize(ll n) {
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}



int main(){
	int n; cin >> n;
        int  ans = 0;
	for(int i = 1; i <= n; i+=2){
	    auto vec = prime_factorize(i);
	    int tmp = 1;
	    for(auto it : vec){
		    tmp *= (it.second+1);
        }
        if(tmp==8){
++ans;
        }
	}
cout << ans << endl;
	
    return 0;
}