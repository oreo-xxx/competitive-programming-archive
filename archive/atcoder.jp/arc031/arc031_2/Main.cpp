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

int num = 0;
int lands_num = 0;
bool isChecked[10][10];

void dfs(int x, int y){
    ++num;
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
        if(field[ny][nx] == 'x'){
            continue;
        }
        dfs(nx, ny);
    }
    return;
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    H = W = 10;
    field.resize(H);
    for(int i = 0; i < H; ++i){
        cin >> field[i];
    }

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(field[i][j] == 'o'){
                ++lands_num;
            }
        }
    }

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            if(field[i][j] != 'o'){
                field[i][j] = 'o';
                num = 0;
                memset(isChecked, 0, sizeof(isChecked));
                dfs(j,i);
                if(num == lands_num + 1){
                    cout << "YES" << endl;
                    return 0;
                }
                field[i][j] = 'x';
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

