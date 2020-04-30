#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int k, s; cin >> k >> s;
    ll count = 0;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            int l = s - i - j;
            if (0 <= l && l <= k){
                ++count;
            }
        }
    }
    cout <<  count << endl;
    return 0;
}

