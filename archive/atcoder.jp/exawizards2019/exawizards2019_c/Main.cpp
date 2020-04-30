#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char, char>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int simulate(const string &s, const vector<P> &td, int pos) {
    for (auto c : td) {
        if (s[pos] != c.first) continue;
        if (c.second == 'L') --pos;
        else ++pos;
        if (pos < 0) return -1; // 左に落ちる
        if (pos >= s.size()) return 1; // 右に落ちる
    }
    return 0;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, Q; string s; cin >> N >> Q >> s;
    vector<P> td(Q);
    for (int i = 0; i < Q; ++i){
        cin >> td[i].first >> td[i].second;
    }

    // 左側の境目
    int low = -1, high = N;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (simulate(s, td, mid) == -1) low = mid;
        else high = mid;
    }
    int left_fall = high;

    // 右側の境目
    low = -1, high = N;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (simulate(s, td, mid) == 1) high = mid;
        else low = mid;
    }
    int right_fall = N-1-low;

    cout << N - (left_fall + right_fall) << endl;

    return 0;
}
