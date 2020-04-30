#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    ll r, d, x; cin >> r >> d >> x;
    for(int i = 0; i < 10; ++i){
        x = r * x - d;
        cout << x << endl;
    }

    return 0;
}

