#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

bool dp[110000];

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) {
                dp[i] |= !dp[i - a[j]];
            }
        }
    }

    if (dp[k]){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
}

