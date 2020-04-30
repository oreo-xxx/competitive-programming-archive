#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve() {
    cout << setprecision(10);

    long double a, b, x;
    cin >> a >> b >> x;
    long double total = a * a * b;
    long double half = total / 2.0;
    if(x >= half){
        long double ans = atan(2.0 * (a * a * b - x) / (a * a * a)) * 180.0 / M_PI;
        cout << ans  << endl;
    }
    else{
        long double tmp = atan(2.0 * x / (a * b * b)) * 180.0 / M_PI;
        long double ans = 90.0 - tmp;
        cout << ans << endl;
    }
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

