#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;


int main() {
    int n, k; cin >> n >> k;
    vector<ll> h(n);
    vector<ll> dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    fill(dp.begin(), dp.end(), INF);

    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        for(int j = 1; j <= k; ++j){
            if(i - j >= 0){
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    }

    cout << dp[n-1] << endl;
}