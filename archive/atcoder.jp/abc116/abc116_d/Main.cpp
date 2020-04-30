#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 40;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
    long long N, K; cin >> N >> K;
    vector<vector<long long> > s(N); // s[i] := 種類 i の美味しさの集合
    for (int i = 0; i < N; ++i) {
        long long t, d; cin >> t >> d; --t;
        s[t].push_back(d);
    }

    // 各種類について、美味しい順に並べる
    for (auto &v : s) {
        sort(v.begin(), v.end(), greater<long long>());
        if (v.empty()) v.push_back(-INF); // 番兵
    }

    // 「美味しさの最大値」の大きいネタ順
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) {
            return a[0] > b[0];});
 
    // まず K 種類選ぶ場合
    long long cur = 0;
    priority_queue<long long> que;
    for (int i = 0; i < K; ++i) {
        cur += s[i][0];
        for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
    }
    for (int i = K; i < N; ++i) for (int j = 0; j < s[i].size(); ++j) que.push(s[i][j]);

    // 走査
    long long res = cur + K*K;
    for (long long x = K-1; x >= 1; --x) {
        long long v = s[x][0];
        long long w = que.top();
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x*x);
    }
    cout << res << endl;
    
}