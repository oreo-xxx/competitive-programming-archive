#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<P> res;
    int dame = N;
    if (N % 2 == 1) --dame;

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (j == dame) continue;
            res.push_back(P(i, j));
        }
        --dame;
    }

    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}
