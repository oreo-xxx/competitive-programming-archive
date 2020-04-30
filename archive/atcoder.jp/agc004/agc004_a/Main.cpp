#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll A, B, C; cin >> A >> B >> C;

    ll ans = 0;
    if (A % 2 != 0 && B % 2 != 0 && C % 2 != 0){
        ans = min({A*B, B*C, C*A});
    }

    cout << ans << endl;
    return 0;
}
