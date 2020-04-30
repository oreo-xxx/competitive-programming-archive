#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const long long INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if (a[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }

    // しゃくとり法
    int ans = 0;
    int right = 0;
    ll mul = 1;
    for (int left = 0; left < n; ++left) {
        while (right < n && mul * a[right] <= k) {
            mul *= a[right];
            ++right;
        }

        ans = max(ans, right - left);
        if (left == right){
            ++right;
        }
        else{
            mul /= a[left];
        }
    }

    cout << ans << endl;
}

