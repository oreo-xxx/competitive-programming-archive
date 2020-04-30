#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; string S;
    cin >> N >> S;

    string mae = S.substr(0, N);
    string ushi = S.substr(N, N);

    map<pair<string,string>, ll > mp;
    for (int bit = 0; bit < (1<<N); ++bit) {
        string a, b;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)){
                a += ushi[i];
            }
            else{
                b += ushi[i];
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ++mp[{a, b}];
    }

    ll res = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        string a, b;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)){
                a += mae[i];
            }
            else{
                b += mae[i];
            }
        }
        res += mp[{b, a}];
    }

    cout << res << endl;
    return 0;
}

