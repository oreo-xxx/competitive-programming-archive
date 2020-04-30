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
    int N; cin >> N;
    string s, t; cin >> s >> t;

    int ans = 2 * N;
    for (int i = 0; i < N; ++i) {
        string s_right {s.substr(i)};
        string t_left {t.substr(0, N-i)};
        if ( s_right == t_left ){
            ans = i + N;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
