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

ll N, K;
vector<int> A;
set<int> sA;
vector<string> S;

string solve() {
    // 共通prefixの作成
    string res = "";
    for (int i = 0; i < 100000; ++i) {
        set<char> se;
        bool ok = true;
        for (auto a : A) {
            if (i >= S[a].size()) {
                ok = false;
                break;
            }
            se.insert(S[a][i]);
        }
        if (!ok || se.size() > 1) break;
        res += *se.begin();
    }

    int ma = 0;
    for (int i = 0; i < N; ++i) {
        if (sA.count(i)) continue;
        if (S[i].size() >= res.size() && S[i].substr(0, res.size()) == res) return "-1";
        int pl = min(res.size() - 1, S[i].size());
        for (int j = min(res.size(), S[i].size()) - 1; j >= 0; --j) {
            if (res[j] != S[i][j]) pl = j;
        }
        ma = max(ma, pl+1);
    }

    return res.substr(0, ma);
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N >> K;
    S.resize(N);
    A.resize(K);
    for (int i = 0; i < K; ++i){
        cin >> A[i];
        --A[i];
        sA.insert(A[i]);
    }

    for (int i = 0; i < N; ++i){
        cin >> S[i];
    }
    cout << solve() << endl;
}
