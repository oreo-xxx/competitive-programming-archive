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

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S;cin >> S;
    int res = 0;
    for (int i = 0; i < S.size();) {
        int j = i+1;
        while (j < S.size() && S[j] > S[i]) ++j;
        ++res;
        i = j;
    }
    cout << res << endl;
    return 0;
}
