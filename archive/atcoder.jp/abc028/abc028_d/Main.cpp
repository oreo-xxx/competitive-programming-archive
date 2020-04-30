#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	ld n, k;
	cin >> n >> k;
	ld ans = 0.0;
	ans+= (k-1) * 1 * (n-k) * 6;
	ans+=(k-1)* 3;
	ans+=(n-k)* 3;
	ans+=1;
	ans /= n * n * n;
	cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
