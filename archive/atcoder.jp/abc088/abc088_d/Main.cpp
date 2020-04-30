#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int h, w, n;
vector<string> s;
vector< vector<int> >steps;
int power;

void bfs(int sx, int sy, int gx, int gy){
    queue<P> q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front(); q.pop();
        if(x == gx && y == gy) return;
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            if(s[ny][nx]=='#') continue;
            if(steps[ny][nx] != 0) continue;
            steps[ny][nx] = steps[y][x] + 1;
            q.emplace(nx, ny);
        }
    }
    return;
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    cin >> h >> w;
    s.resize(h);
    for(int i = 0;i < h; i++){
        cin>>s[i];
    }
    int num = 1;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(s[i][j] == '#'){
                ++num;
            }
        }
    }

    steps.resize(h);
    for(int j = 0; j < h; j++){
        steps[j].resize(w);
    }

    int sx = 0;
    int sy = 0;
    int gx = w - 1;
    int gy = h - 1;
    bfs(sx, sy, gx, gy);

    int ans = -1;
    if(steps[gy][gx] != 0){
        ans = h * w - num - steps[gy][gx];
    }

    cout << ans << endl;
    return 0;
}

