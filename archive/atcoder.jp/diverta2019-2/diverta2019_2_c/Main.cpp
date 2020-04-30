#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int N;
vector<long long> A;

void solve() {
    // +, - に分ける
    vector<long long> plus, minus;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }
    sort(plus.begin(), plus.end(), greater<long long>());
    sort(minus.begin(), minus.end());
    if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    // 復元
    vector<P> res;
    long long cur = minus[0];
    for (int i = 0; i+1 < plus.size(); ++i) {
        res.push_back({cur, plus[i]});
        cur -= plus[i];
    }
    res.push_back({plus.back(), cur});
    cur = plus.back() - cur;

    for (int i = 1; i < minus.size(); ++i) {
        res.push_back({cur, minus[i]});
        cur -= minus[i];
    }

    cout << cur << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    solve();
}
