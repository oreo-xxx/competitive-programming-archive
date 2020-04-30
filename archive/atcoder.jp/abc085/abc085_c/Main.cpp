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

    int n, y; cin >> n >> y;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; i + j <= n; ++j) {
            int k = n - i - j;
            if (10000 * i + 5000 * j + 1000 * k == y ){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout <<  "-1 -1 -1" << endl;
    return 0;
}

