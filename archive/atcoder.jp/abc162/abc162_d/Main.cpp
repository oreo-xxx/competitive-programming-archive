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
    ll n; cin >> n;
    string s; cin >> s;
    vector<int> r(n+1), g(n+1), b(n+1);
    for (int i = 0; i < n; ++i) {
        r[i+1] = r[i];
        g[i+1] = g[i];
        b[i+1] = b[i];
        if(s[i]=='R') ++r[i+1];
        if(s[i]=='G') ++g[i+1];
        if(s[i]=='B') ++b[i+1];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(s[i] == s[j]) continue;

            int d = j-i;

            if(s[i]=='R'){
                if(s[j]=='G'){
                    ans += b[n] - b[j];
                    if(j + d < n && s[j+d]=='B'){
                        --ans;
                    }
                }
                else if (s[j]=='B'){
                    ans += g[n] - g[j];
                    if(j + d < n && s[j+d]=='G') --ans;
                }
            }
            if(s[i]=='G'){
                if(s[j]=='R'){
                    ans += b[n] - b[j];
                    if(j + d < n && s[j+d]=='B') --ans;
                }
                else if (s[j]=='B'){
                    ans += r[n] - r[j];
                    if(j + d < n && s[j+d]=='R') --ans;
                }
            }
            if(s[i]=='B'){
                if(s[j]=='R'){
                    ans += g[n]- g[j];
                    if(j + d < n && s[j+d]=='G') --ans;
                }
                else if (s[j]=='G'){
                    ans += r[n]- r[j];
                    if(j + d < n && s[j+d]=='R') --ans;
                }
            }
        }
    }
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
