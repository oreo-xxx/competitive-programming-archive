#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int H, W;
int sx, sy, gx, gy;
vector<string> field;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
bool isChecked[500][500];

bool dfs(int x, int y){
    if(x == gx && y == gy)return true;
    isChecked[y][x] = true;
    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || W <= nx || ny < 0 || H <= ny){
            continue;
        }
        if(isChecked[ny][nx]){
            continue;
        }
        if(field[ny][nx] == '#'){
            continue;
        }
        if(dfs(nx, ny)){
            return true;
        }
    }
    return false;
}


int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    cin >> H >> W;
    field.resize(H);
    for(int i = 0; i < H; ++i){
        cin >> field[i];
    }
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(field[i][j] == 's'){
                sx = j;
                sy = i;
            }
            if(field[i][j] == 'g'){
                gx = j;
                gy = i;
            }
        }
    }

    string ans = "No";
    if(dfs(sx, sy)){
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}

