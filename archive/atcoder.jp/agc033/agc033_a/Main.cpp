#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int h, w, n;
vector<string> s;
vector< vector<int> >steps;

void bfs(vector<P> &starts){
    queue<P> q;
    for(auto s : starts){
        q.push(s);
        steps[s.first][s.second] = 0;
    }

    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front(); q.pop();
        for(int k = 0; k < 4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            if(s[ny][nx] == '#') continue;
            s[ny][nx] = '#';
            steps[ny][nx] = min(steps[ny][nx], steps[y][x] + 1);
            q.emplace(ny, nx);
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
    steps.resize(h);
    for(int i = 0;i < h; i++){
        steps[i].resize(w);
    }

    vector<P> starts;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            steps[i][j] = INF32;
            if(s[i][j] == '#'){
                starts.push_back(make_pair(i, j));
            }
        }
    }

    bfs(starts);

    int ans = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            ans = max(ans, steps[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}

