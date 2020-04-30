#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

ll next(ll n) {
    if (n % 2 == 0) return n/2;
    else return n*3 + 1;
}


int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int P; cin >> P;
    ll start = 1789997546303LL;
    for (int i = 0; i < 1000 - P; ++i) {
        start = next(start);
    }
    cout << start << endl;
    return 0;
}
