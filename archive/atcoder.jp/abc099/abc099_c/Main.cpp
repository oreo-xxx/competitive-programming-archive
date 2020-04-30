#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int NMAX = 100000;
int main() {
    #ifdef MYLOCAL
        ifstream in("input.txt");
        cin.rdbuf(in.rdbuf());
    #endif

    int n; cin >> n;

    set<ll> coins;
    for(int i = 0; i < n; ++i){
        if(pow(6, i) <= n) coins.insert((pow(6, i)));
        if(pow(9, i) <= n) coins.insert((pow(9, i)));
    }

    ll dp[n + 1];
    fill(dp, dp + n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        for(auto it : coins){
            if( i - it >= 0){
                dp[i] = min(dp[i], dp[i - it] + 1);
            }
        }
    }

    cout << dp[n] << endl;
}