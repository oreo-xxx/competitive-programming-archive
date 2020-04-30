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
	ll  n, m;cin >>n>> m;
	map<ll, int> mp;
	for(int i = 0; i < m; ++i) {
		ll a, b;cin >>a>> b;
		mp[a]++; mp[b]++;
    }
    for(auto it : mp){
        if(it.second%2==1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
