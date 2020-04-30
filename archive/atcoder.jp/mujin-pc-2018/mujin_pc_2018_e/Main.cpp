#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
const int MOD = 998244353;

// Lib
//

const int dx[4] = {1, 0, -1, 0}; // D, R, U, L
const int dy[4] = {0, 1, 0, -1};

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, M, K; string d;
    cin >> N >> M >> K >> d;

    vector<string> fi(N);
    int sx, sy, tx, ty;
    for (int i = 0; i < N; ++i) {
        cin >> fi[i];
        for (int j = 0; j < M; ++j) {
            if (fi[i][j] == 'S') sx = i, sy = j;
            else if (fi[i][j] == 'G') tx = i, ty = j;
        }
    }

    vector<ll> timing[4];
    for (int i = 0; i < K; ++i) {
        int dir = -1;
        if (d[i] == 'D') dir = 0;
        else if (d[i] == 'R') dir = 1;
        else if (d[i] == 'U') dir = 2;
        else dir = 3;
        timing[dir].push_back(i);
        timing[dir].push_back(i+K);
    }
    for (int dir = 0; dir < 4; ++dir){
        sort(timing[dir].begin(), timing[dir].end());
    }

    vector<vector<ll> > dp(N, vector<ll>(M, INF64));
    dp[sx][sy] = 0;

    priority_queue<pair<ll, P>, vector<pair<ll,P> >, greater<pair<ll,P> > > que;
    que.push({0, {sx, sy}});
    while (!que.empty()) {
        auto cur = que.top(); que.pop();
        ll dist = cur.first;
        int x = cur.second.first;
        int y = cur.second.second;

        if (dist > dp[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || timing[dir].empty()) continue;
            if (fi[nx][ny] == '#') continue;
            int ord = dist % K;
            ll wait = *lower_bound(timing[dir].begin(), timing[dir].end(), ord) - ord;
            ll ndist = dist + wait + 1;
            if (dp[nx][ny] > ndist) {
                dp[nx][ny] = min(dp[nx][ny], ndist);
                que.push({ndist, {nx, ny}});
            }
        }
    }
    ll ans = -1;
    if(dp[tx][ty] < INF64){
        ans = dp[tx][ty];
    }
    cout << ans << endl;

    return 0;
}
