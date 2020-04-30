#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int h, w;
int sx, sy;
int gx, gy;
vector<string> s;
vector< vector<int> > steps;

void bfs(){
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
    cin >> sy >> sx;
    cin >> gy >> gx;
    --sx; --sy; --gx; --gy;

    s.resize(h);
    steps.resize(h);
    for(int i = 0;i < h; i++){
        cin>>s[i];
        steps[i].resize(w);
    }

    bfs();

    cout << steps[gy][gx] << endl;
    return 0;
}

