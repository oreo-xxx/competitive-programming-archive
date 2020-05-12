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

const int CASES = 3;

ll n, m, q;
vector<ll> a, b, c, d;
int buf[10];
ll ans = 0;
void rec(int i){
    if(i == n){
        ll tmp = 0;
        for(int j = 0; j < q; ++j){
            if(buf[a[j]] - buf[b[j]] + c[j] == 0) tmp += d[j];
        }
        ans = max(ans, tmp);
    }
    else{
        for(int j = buf[i-1]; j <= m; ++j){
            buf[i] = j;
            rec(i+1);
        }
    }
}

void solve() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for(int i = 0; i < q; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }
    buf[0] = 1;
    rec(1);
    cout << ans << endl;
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
