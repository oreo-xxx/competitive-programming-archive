#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

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

int main(){
    int n; cin >> n;
    vector<P> a(n), b(n);
    for(int i = 0; i < n; ++i){
    	 int ai, bi; cin >> ai >> bi;
         a[i] = {ai, bi};
    }
    for(int i = 0; i < n; ++i){
    	 int ci, di; cin >> ci >> di;
         b[i] = {ci, di};
    }
    
    HopcroftKarp hk(n, n);
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < n; ++j){
    	    if(a[i].first < b[j].first && a[i].second < b[j].second){
    	        hk.addedge(i,j);
            }
        }
    }
    
    int ans = hk.solve();
    cout << ans << endl;
    
    return 0;
}