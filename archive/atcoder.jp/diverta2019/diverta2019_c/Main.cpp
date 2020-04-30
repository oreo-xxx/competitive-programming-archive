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
vector<string> S;

int count(const string &str) {
    int res = 0;
    for (int i = 0; i+1 < str.size(); ++i) {
        if (str[i] == 'A' && str[i+1] == 'B'){
            ++res;
        }
    }
    return res;
}

long long solve() {
    long long res = 0;
    for (int i = 0; i < N; ++i) res += count(S[i]);

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i][0] == 'B' && S[i].back() == 'A') ++a;
        else if (S[i].back() == 'A') ++b;
        else if (S[i][0] == 'B') ++c;
    }
    long long add = 0;
    if (b + c == 0) add = max(0, a-1);
    else add = a + min(b, c);

    res += add;
    return res;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> N;
    S.resize(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    cout << solve() << endl;
    return 0;
}
