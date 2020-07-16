#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 2;
void solve() {
    ld A, B, H, M; cin >> A >> B >> H >> M;
    ld ang1 = H * 30.0;
    ang1 += M * 0.5;
    ld ang2 = M * 6.0;
    ld ang = abs(ang1-ang2);
    ang /= 180.0;
    ang *= M_PI;
    ld ans = sqrt(A*A + B*B - 2.0*A*B*cos(ang));
    cout << fixed << setprecision(12) << ans << endl;

}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
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
