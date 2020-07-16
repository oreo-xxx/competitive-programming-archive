#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<int, int>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

// 集計時に園児のいる園を集めるだと遅い…(O(nlogn)を繰り返す)
// ->最強園児を管理しておく！

int main(){
    int n, q; cin >> n >> q;
    vector<ll> a(n);
    vector<multiset<ll>> se(200010);
    map<ll, ll> mp; //所属
    multiset<ll> strongs;
    for(int i = 0; i < n; ++i){
        int b;
        cin >> a[i] >> b; --b;
        se[b].insert(a[i]);
        mp[i] = b;
		if (se[b].size() == 1) {
			strongs.insert(a[i]);
		}
        else{
			auto itr = se[b].end(); --itr;
			if (*itr == a[i]) {
				--itr;
				strongs.erase(strongs.find(*itr));
				strongs.insert(a[i]);
			}
        }
    }
    for(int i = 0; i < q; ++i){
        int c, d;
        cin >> c >> d; --c; --d;

        // 転園
        int prev = mp[c];
        se[prev].erase(se[prev].find(a[c]));
        se[d].insert(a[c]);
        mp[c] = d;
        
        // 最強が更新しているか - 前の園
		if (se[prev].size() == 0) {
			strongs.erase(strongs.find(a[c]));
		}
		else {
			auto itr = se[prev].end(); --itr;
			if (*itr < a[c]) {
				strongs.erase(strongs.find(a[c]));
				strongs.insert(*itr);
			}
		}
        // 最強が更新しているか - 次の園
		if (se[d].size() == 1) {
			strongs.insert(a[c]);
		}
		else {
			auto itr = se[d].end(); --itr;
			if (*itr == a[c]) {
				--itr;
				strongs.erase(strongs.find(*itr));
				strongs.insert(a[c]);
			}
		}
		auto ans = strongs.begin();
        cout << *ans << endl;
    }
    
}