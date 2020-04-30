#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<long double, long double>;

const ll INF64 = 1LL << 60;
const int INF = 1 << 29;
const ll MOD = 998244353;

const int CASES = 3;

long double calc(P a, P b){
    long double tmp = (a.first - b.first) * (a.first - b.first);
    tmp += (a.second - b.second) * (a.second - b.second);
    return sqrt(tmp);
}

void solve() {
    int n; cin >> n;
    vector<P> a(n);
    for(int i =0; i < n; ++i){
        long double x, y; cin >> x >> y;
        a[i] = {x, y};
    }

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    long double count = 0.0;
    long double ans = 0.0;
    do {
        for(int i =0; i < n-1; ++i){
            ans += calc(a[v[i+1]], a[v[i]]);
        }
        ++count;
    } while( next_permutation(v.begin(), v.end()) );
    ans /= count;
    cout  << setprecision(10) << ans << endl;
    return;
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

