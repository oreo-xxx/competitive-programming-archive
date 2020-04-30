#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;

// vector v において、x の前方と後方の index を求める
template<class T> int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}
template<class T> int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void solve(){
    int A, B, Q; cin >> A >> B >> Q;

    vector<ll> s(A), t(B);
    for (int i = 0; i < A; ++i) cin >> s[i];
    for (int i = 0; i < B; ++i) cin >> t[i];

    // sential
    s.push_back(INF64); s.push_back(-INF64); sort(s.begin(), s.end());
    t.push_back(INF64); t.push_back(-INF64); sort(t.begin(), t.end());

    for (int _ = 0; _ < Q; ++_) {
        ll x; cin >> x;
        ll res = INF64;

        // 最初に s (前方に行くか後方に行くか場合分け)
        for (int i = 0; i < 2; ++i) {
            ll first = (i ? s[former(s, x)] : s[latter(s, x)]);
            // 次に t (現在地の前後を見る)
            for (int j = 0; j < 2; ++j) {
                ll second = (j ? t[former(t, first)] : t[latter(t, first)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }
        // 最初に t (前方に行くか後方に行くか場合分け)
        for (int i = 0; i < 2; ++i) {
            ll first = (i ? t[former(t, x)] : t[latter(t, x)]);
            // 次に t (現在地の前後を見る)
            for (int j = 0; j < 2; ++j) {
                ll second = (j ? s[former(s, first)] : s[latter(s, first)]);
                res = min(res, abs(x - first) + abs(first - second));
            }
        }
        cout << res << endl;
    }
    return;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

