#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string L; cin >> L;
    int n = L.size();

    ll dp[100010][2] {};
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        dp[i+1][1] += 3 * dp[i][1];
        dp[i+1][1] %= MOD;
        if(L[i] == '1'){
            dp[i+1][0] += 2 * dp[i][0];
            dp[i+1][0] %= MOD;
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] %= MOD;
        }else{
            dp[i+1][0] += dp[i][0];
            dp[i+1][0] %= MOD;
        }
    }

    ll ans = (dp[n][0] + dp[n][1]) % MOD;
    cout << ans << endl;
    return 0;
}
