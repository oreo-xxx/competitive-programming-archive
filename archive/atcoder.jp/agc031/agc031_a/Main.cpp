#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

long long num[30];

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; string S; cin >> N >> S;
    for (auto c : S){
        num[c - 'a']++;
    }

    ll res = 1;
    for (int i = 0; i < 26; ++i) {
        res *= num[i] + 1;
        res %= MOD;
    }
    res -= 1;

    cout << (res + MOD) % MOD << endl;
    return 0;
}
