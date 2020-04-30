#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int nex[201010][26] {};

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S, T; cin >> S >> T;
    int A = S.size();

    // Sの部分列として各位置を取ったとき
    // その次にa～zをそれぞれ取る場合何文字先の文字が最寄であるか
    S += S;
    for(int j = 0; j < 26; ++j){
        nex[2 * A][j] = 2 * A;
    }
    for(int i = 2 * A - 1; i >= 0; i--) {
        for(int j = 0; j < 26; ++j){
            nex[i][j] = nex[i + 1][j];
        }
        nex[i][S[i]-'a'] = i + 1;
    }

    ll cur = 0;
    for(auto c : T) {
        c -= 'a';
        int x = cur % A;

        if(nex[x][c] == 2 * A){
            cout << "-1" << endl;
            return 0;
        }

        cur += nex[x][c] - x;
    }
    cout << cur << endl;
    return 0;
}

