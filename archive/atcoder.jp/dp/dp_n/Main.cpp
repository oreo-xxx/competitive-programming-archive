#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll dp[404][404];
int flag [404][404];
vector<ll> a, sum;
int n;

ll f(int l,int r){
	if(flag[l][r])return dp[l][r];
	flag[l][r]=1;
	if(l==r)return 0;
	//どこで切るか全通り試す
	ll fans=INF64;
	for(int m = l; m < r; ++m){
		fans = min(fans, f(l, m) + f(m+1, r));
    }
	
	return dp[l][r]=fans+sum[r+1]-sum[l];
}

int main(){
	cin >> n;
	a.resize(n); sum.resize(n+1);
	for(int i = 0; i < n; ++i){
        cin >> a[i]; sum[i+1] = sum[i] +a[i];
    } 
	
	ll ans = f(0, n-1);
    cout << ans << endl;
}