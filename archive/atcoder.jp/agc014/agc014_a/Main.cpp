#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//
uint64_t dp[101010][13]; // mod13

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll A, B, C; cin >> A >> B >> C;

    int ans = -1;
    for (int i = 0; i < 100; ++i) {
        if ( (A & 1) || (B & 1) || (C & 1)){
            ans = i;
            break;
        }
        ll tA = (B + C) / 2;
        ll tB = (C + A) / 2;
        ll tC = (A + B) / 2;
        A = tA, B = tB, C = tC;
    }
    cout << ans << endl;
    return 0;
}
