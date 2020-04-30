#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 0; i < n; ++i){
        double x; string u;
        cin >> x >> u;
        if(u == "JPY"){
            ans += x;
        }
        else{
            ans += 380000.0 * x;
        }
    }
    cout << ans << endl;
    return 0;
}

