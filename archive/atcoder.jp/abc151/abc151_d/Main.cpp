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

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int h, w;
int sx, sy;
int gx, gy;
vector<string> s;

int bfs(){
    if(s[sy][sx]=='#') return 0;
    vector< vector<int> > steps(h, vector<int>(w));

    queue<pint> q;
    q.push(make_pair(sx, sy));

    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            if(s[ny][nx]=='#') continue;
            if(ny == sy && nx == sx) continue;
            if(steps[ny][nx] != 0) continue;
            steps[ny][nx] = steps[y][x] + 1;
            q.emplace(nx, ny);
        }
    }
    int ret = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ret = max(ret, steps[i][j]);
        }
    }
    return ret;
}

void solve() {
    cin >> h >> w;
    s.resize(h);
    for(int i = 0; i < h; ++i){
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            sy = i;
            sx = j;
            int tmp = bfs();
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
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
