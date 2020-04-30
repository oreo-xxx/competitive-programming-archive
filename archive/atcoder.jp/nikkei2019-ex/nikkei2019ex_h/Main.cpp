#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int ans[9] = {0, 1, 0, 1, 0, 1, 0, 1, 1};

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    ll n; cin >> n;
    if (ans[n%9]) cout << "Win" << endl;
    else cout << "Lose" << endl;
    return 0;
}
