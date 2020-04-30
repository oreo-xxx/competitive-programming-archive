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

void bfs(P start, P goal){
    deque<P> q;
    q.push_front(start);
    steps[start.first][start.second] = 0;

    while(!q.empty()){
        int y, x;
        tie(y, x) = q.front(); q.pop_front();
        if(goal.first == y && goal.second == x){
            return;
        }
        for(int k = 0; k < 4; k++){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            if(s[ny][nx] == '#'){
                if( steps[ny][nx] > steps[y][x] + 1){
                    steps[ny][nx] = min(steps[ny][nx], steps[y][x] + 1);
                    q.push_back(make_pair(ny, nx));
                }
            }
           else{
                if( steps[ny][nx] > steps[y][x]){
                    steps[ny][nx] = min(steps[ny][nx], steps[y][x]);
                    q.push_front(make_pair(ny, nx));
                }
            }
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

    P start, goal;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            steps[i][j] = INF32;
            if(s[i][j] == 's'){
                start = {i, j};
            }
            if(s[i][j] == 'g'){
                goal = {i, j};
            }
        }
    }

    bfs(start, goal);

    if(steps[goal.first][goal.second] <= 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

