#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

// Lib
//

using type = pair<int, long long>; // 1: query, 0; delete, -1: insert
using event = pair<long long, type>;

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, Q; cin >> N >> Q;
    vector<event> v;
    for (int i = 0; i < N; ++i) {
        int s, t, x; cin >> s >> t >> x;
        v.push_back({s-x, type(-1, x)});
        v.push_back({t-x, type(0, x)});
    }
    for (int i = 0; i < Q; ++i) {
        int d; cin >> d;
        v.push_back({d, type(1, i)});
    }
    sort(v.begin(), v.end());

    vector<long long> res(Q);
    multiset<long long> se;
    for (auto p : v) {
        long long x = p.first;
        int type = p.second.first;
        long long val = p.second.second;
        if (type == -1) se.insert(val);
        else if (type == 0) se.erase(se.lower_bound(val));
        else res[val] = (se.empty() ? -1 : *(se.begin()));
    }
    for (auto v : res) cout << v << endl;
    return 0;
}
