#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    int H, W;
    cin >> H >> W;
    string A[101];
    for(int y = 0; y < H; ++y) cin >> A[y];

    map<char, int> cnt;
    for(int y = 0; y < H; ++y){
        for(int x = 0; x < W; ++x){
            ++cnt[A[y][x]];
        }
    }

    if (H % 2 == 0 && W % 2 == 0) {
        for(auto p : cnt){
            if (p.second % 4 != 0){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }

    map<int, int> c;
    for(auto p : cnt){
        ++ c[p.second % 4];
    }

    if (H % 2 == 1 && W % 2 == 1) {
        if( (c[3] > 0)
        || (c[1] != 1)
        || (c[2] > (H - 1) / 2 + (W - 1) / 2) ){
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }

    if (W % 2 == 1){
        swap(H, W);
    }

    if( (c[1] || c[3])
    || (c[2] > W / 2)){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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

