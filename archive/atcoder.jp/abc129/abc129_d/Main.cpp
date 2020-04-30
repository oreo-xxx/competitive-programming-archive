#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

int H, W;
vector<string> field;

int tate[2100][2100] = {};
int yoko[2100][2100] = {};

void lightcount_tate(int h, int w){
    if(field[h][w] == '#'){
        return;
    }
    if(tate[h][w] != 0){
        return;
    }
    int count = 1;
    int lim = 0;
    for(lim = h + 1; lim < H; ++lim){
        if(field[lim][w] == '.'){
            ++count;
        }
        else{
            break;
        }
    }
    for(int i = h; i < lim; ++i){
        tate[i][w] = count;
    }
}

void lightcount_yoko(int h, int w){
    if(field[h][w] == '#'){
        return;
    }
    if(yoko[h][w] != 0){
        return;
    }
    int count = 1;
    int lim = 0;
    for(lim = w + 1; lim < W; ++lim){
        if(field[h][lim] == '.'){
            ++count;
        }
        else{
            break;
        }
    }
    for(int i = w; i < lim; ++i){
        yoko[h][i] = count;
    }
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
            lightcount_tate(i, j);
            lightcount_yoko(i, j);
        }
    }

    int ans = 0;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            ans = max(ans, tate[i][j] + yoko[i][j] - 1);
        }
    }

    cout << ans << endl;
    return 0;
}

