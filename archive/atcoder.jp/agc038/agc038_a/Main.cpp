#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;

void solve(){
    int H, W, A, B;
    cin >> H >> W >> A>> B;

    vector<string> ans(H);
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(i < B && j < A) ans[i] += "0";
            else if(i >= B && j >= A) ans[i] += "0";
            else ans[i] += "1";
        }
    }

    for(int i = 0; i < H; ++i){
        cout << ans[i] << '\n';}

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

