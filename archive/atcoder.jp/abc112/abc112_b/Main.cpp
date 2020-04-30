#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    int n, t; cin >> n >> t;
    int ans = INF32;
    for(int i = 0; i < n; ++i){
    	int c, tmp; cin >> c >> tmp;
        if(tmp <= t){
        	ans = min(ans, c);
        }
    }
    if(ans == INF32){cout << "TLE" << endl;}
    else{cout << ans << endl;}
    return 0;
}