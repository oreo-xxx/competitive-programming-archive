#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > field(H);
    vector<vector<int> > used(H);
    for(int y = 0; y < H; ++y){
        field[y].resize(W);
        used[y].resize(W);
        for(int x = 0; x < W; ++x){
            cin >> field[y][x];
        }
    }


    vector< pair<P, P> > ans;
    for(int y = 0; y < H; ++y){
        for(int x = 0; x < W-1; ++x){
            if(field[y][x] % 2 != 0){
                ans.push_back({ {y + 1, x + 1}, {y + 1,x + 2}});
                used[y][x] = 1;
                --field[y][x];
                ++field[y][x+1];
            }
        }
    }

    for(int y = 0; y < H-1; ++y){
        for(int x = 0; x < W; ++x){
            if( field[y][x] % 2 != 0){
                ans.push_back({ {y + 1, x + 1}, {y + 2,x + 1}});
                --field[y][x];
                ++field[y+1][x];
            }
        }
    }

    cout << ans.size() << endl;
    for(auto itr : ans){
        cout << itr.first.first << " " << itr.first.second << " " << itr.second.first << " " << itr.second.second << endl;
    }

    return ;
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

