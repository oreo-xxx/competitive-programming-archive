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
	ll  n; cin >>n;
	ll ans = 0;
	ans+=(n/11)*  2;
	if(n%11!=0){
	if(n%11<=6){ans++;}
	else{ans+=2;}
	}
	
    cout << ans << endl;
}
