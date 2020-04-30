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
    vector<ll> A(9);
    for(int i = 0; i < 9; ++i){
        cin >> A[i];
    }
    ll N; cin >> N;
    vector<ll> used(9);
    for(int i = 0; i < N; ++i){
        ll B; cin >> B;
        for (int j = 0; j < 9; ++j) {
            if(B == A[j]){
                used[j] = true;
            }
        }
    }
    bool f = false;
    if(used[0] == true && used[1] == true && used[2] == true) f = true;
    if(used[3] == true && used[4] == true && used[5] == true) f = true;
    if(used[6] == true && used[7] == true && used[8] == true) f = true;
    if(used[0] == true && used[3] == true && used[6] == true) f = true;
    if(used[1] == true && used[4] == true && used[7] == true) f = true;
    if(used[2] == true && used[5] == true && used[8] == true) f = true;
    if(used[0] == true && used[4] == true && used[8] == true) f = true;
    if(used[2] == true && used[4] == true && used[6] == true) f = true;
    string ans = "No";
    if(f) ans = "Yes";
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
