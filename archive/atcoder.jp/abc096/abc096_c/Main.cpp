#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

int H, W;
vector<string> field;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool dfs(int y, int x, int count){
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || W <= nx || ny < 0 || H <= ny){
            continue;
        }
        if(field[ny][nx] == '#'){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> H >> W;
    field.resize(H);
    for(int i = 0; i < H; ++i){
        cin >> field[i];
    }
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(field[i][j] == '#'){
                if(!dfs(i, j, 0)){
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    cout << "Yes" << endl;
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

