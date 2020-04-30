#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


#define all(c) ((c).begin()), ((c).end())
struct edge {
  int src, dst;
  int weight;
};
struct graph {
  int n;
  vector<edge> edges;
  graph(int n = 0) : n(n) { }
  void add_edge(int src, int dst, int weight) {
    n = max(n, max(src, dst)+1);
    edges.push_back({src, dst, weight});
  }
  vector<int> p; 
  int root(int i) { 
    return p[i] < 0 ? i : p[i] = root(p[i]); 
  }
  bool unite(int i, int j) {
    if ((i = root(i)) == (j = root(j))) return false;
    if (p[i] > p[j]) swap(i, j);
    p[i] += p[j]; p[j] = i;
    return true;
  }
  int kruskal() {
    p.assign(n, -1);
    sort(all(edges), [](edge x, edge y) {
        return x.weight < y.weight; 
    });
    int result = 0;
    for (auto e: edges) 
      if (unite(e.src, e.dst)) 
        result += e.weight;
    return result;
  }
};


int main(){
	int n; cin >> n;
	vector<P> xy(n), yx(n);
	for(int i = 0; i < n; ++i){
		int x, y;cin >>x >> y;
		xy[i] = {x, i};
		yx[i] = {y, i};
    }
    sort(xy.begin(), xy.end());
    sort(yx.begin(), yx.end());
    graph g;
    for(int i = 0; i < n-1; ++i){
    	g.add_edge(xy[i].second, xy[i+1].second, xy[i+1].first - xy[i].first );
        g.add_edge(xy[i+1].second, xy[i].second, xy[i+1].first - xy[i].first );
        g.add_edge(yx[i].second, yx[i+1].second, yx[i+1].first - yx[i].first );
        g.add_edge(yx[i+1].second, yx[i].second, yx[i+1].first - yx[i].first );
    }
    
    int ans = g.kruskal();
    cout << ans << endl;
    
    return 0;
}