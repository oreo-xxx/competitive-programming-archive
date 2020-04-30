#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

void solve(){
    static int d[303][303];
    static bool d_n[303][303]; // 道路で結ばれていない場合true
    memset(d, 0, sizeof(d));
    memset(d_n, 0, sizeof(d_n));

    int n; cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> d[i][j];
        }
    }

    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(d[i][j] > d[i][k] + d[k][j]){
                    cout << "-1" << endl;
                    return;
                }

                if(d[i][j] == d[i][k] + d[k][j] && d[i][k] > 0 && d[k][j] > 0){
                    d_n[i][j] = true;
                }

            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(d_n[i][j] == false){
                ans += d[i][j];
            }

        }
    }
    cout << ans << endl;
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

