#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};


int main(){
	int n, m;
	cin >> n >> m;
	UnionFind uf(n+1);
	
	vector<pair<int, P> > vec(m);
	for(int i = 0; i < m; ++i){
		int a, b, y; cin >> a >> b >> y;
		vec[i]={-y, {a,b}};
    }
    int q; cin >> q;
    for(int i = 0; i < q; ++i){
    	int c, y; cin >> c >> y;
        vec.push_back({-y, {-1* i, c}});    
    }
    sort(vec.begin(), vec.end());
    
    vector<int> ans(q);
    for(int i = 0; i < q + m; ++i){
    	int a = vec[i].second.first;
        int b = vec[i].second.second;
        if(a<=0){
        	int idx = -1* a;
            ans[idx] = uf.size(b);
        }
        else{
            uf.merge(a, b);
        }
    }
    for(int i = 0; i < q; ++i){
    	cout << ans[i] << endl;
    }
}