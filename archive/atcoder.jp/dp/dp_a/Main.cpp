#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;

int main() {
    int n; cin >> n;
    vector<ll> h(n);
    vector<ll> dp(n);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    fill(dp.begin(), dp.end(), INF);

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[n-1] << endl;
}