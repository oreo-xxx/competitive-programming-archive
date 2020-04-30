#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        int m; cin >> m;
        for(int j = 0; j < m; ++j){
            int k, v; cin >> k>>v;
            --k; ++v;
            a[i][k] = v;
        }
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << n); ++bit){
        vector<int> vec(n);
        int tmp = 0;
        for (int i = 0; i < n; ++i) {
            if ( bit & (1<<i) ) {
                vec[i] = 2;
                ++tmp;
            }
            else{
                vec[i] = 1;
            }
        }
        bool flag = true;
        // i人目が嘘つきか判断
        for (int i = 0; i < n; ++i){
            bool honest = true;
            if(vec[i] == 1) honest = false;
            for (int j = 0; j < n; ++j) {
                //矛盾check
                if(a[i][j]==0) continue;
                if(honest){
                    if(a[i][j] != vec[j]){
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag){
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
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
