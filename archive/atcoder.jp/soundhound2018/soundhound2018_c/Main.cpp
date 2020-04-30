#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<double, double>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

struct HopcroftKarp {
    int sizeL, sizeR;
    vector<vector<int> > list; // left to right

    // result
    vector<bool> seen, matched;
    vector<int> level, matching;

    // base
    HopcroftKarp(int l, int r) : sizeL(l), sizeR(r), list(l, vector<int>()) { }
    inline vector<int>& operator [] (int i) { return list[i]; }
    inline void addedge(int from, int to) { list[from].push_back(to); }
    inline friend ostream& operator << (ostream& s, const HopcroftKarp& G) {
        s << endl;
        for (int i = 0; i < G.list.size(); ++i) {
            s << i << " : ";
            for (int j = 0; j < G.list[i].size(); ++j) {
                s << G.list[i][j];
                if (j + 1 != G.list[i].size()) s << ", ";
            }
            s << endl;
        }
        return s;
    }

    // methods
    void hobfs() {
        queue<int> que;
        for (int left = 0; left < sizeL; ++left) {
            level[left] = -1;
            if (!matched[left]) {
                que.push(left);
                level[left] = 0;
            }
        }
        level[sizeL] = sizeL;
        while (!que.empty()) {
            int left = que.front();
            que.pop();
            for (int i = 0; i < list[left].size(); ++i) {
                int right = list[left][i];
                int next = matching[right];
                if (level[next] == -1) {
                    level[next] = level[left] + 1;
                    que.push(next);
                }
            }
        }
    }
    bool hodfs(int left) {
        if (left == sizeL) return true;
        if (seen[left]) return false;
        seen[left] = true;
        for (int i = 0; i < list[left].size(); ++i) {
            int right = list[left][i];
            int next = matching[right];
            if (level[next] > level[left] && hodfs(next)) {
                matching[right] = left;
                return true;
            }
        }
        return false;
    }
    int solve() {
        seen.assign(sizeL, false);
        matched.assign(sizeL, false);
        level.assign(sizeL+1, -1);
        matching.assign(sizeR, sizeL);
        int res = 0;
        while (true) {
            hobfs();
            seen.assign(sizeL, false);
            bool finished = true;
            for (int left = 0; left < sizeL; ++left) {
                if (!matched[left] && hodfs(left)) {
                    matched[left] = true;
                    ++res;
                    finished = false;
                }
            }
            if (finished) break;
        }
        return res;
    }
};
//

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int R, C; cin >> R >> C;
    vector<string> fi(R);
    for (int i = 0; i < R; ++i){
        cin >> fi[i];
    }

    HopcroftKarp hk(R*C, R*C);
    int V = R*C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int left = i * C + j;
            if (fi[i][j] == '*') {
                --V;
                continue;
            }
            if ( (i + j) % 2 == 1 ){
                continue;
            }
            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (ni < 0 || ni >= R || nj < 0 || nj >= C){
                    continue;
                }
                if (fi[ni][nj] == '*'){
                    continue;
                }
                int right = ni * C + nj;
                hk.addedge(left, right);
            }
        }
    }
    int ans = V - hk.solve();
    cout << ans << endl;
}

