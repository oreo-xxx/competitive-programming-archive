#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using WeightedGraph = vector<vector<pair<int, int>>>;
const int INF = 1 << 29;

const int dx[]={0,1};
const int dy[]={1,0};

int h, w;
int gx, gy;
vector<string> s;
vector<char> s_;
vector< vector<int> > steps;

vector<int> dijkstra(int s, WeightedGraph & G){
  using P = pair<ll, int>;
  int n=G.size();
  vector<int> ds(n,INF);
  vector<int> bs(n,-1);
  priority_queue<P, vector<P>, greater<P> > pq;
  ds[s]=0;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int v=p.second;
    if(ds[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(s_[v] != '#' && s_[u] == '#'){
          ++c;
      }
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}

int main() {
    cin >> h >> w;
    gx = w-1; gy = h-1;

    s.resize(h);
    for(int i = 0;i < h; i++){
        cin>>s[i];
    }
    WeightedGraph G(w*h);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(i<h-1)G[i*w+j].push_back({(i+1)*w+j,0});
            if(j<w-1)G[i*w+j].push_back({i*w+j+1,0});
            s_.push_back(s[i][j]);
        }
    }
    auto ds = dijkstra(0, G);
    int cur = 0;
    if(s[0][0]=='#') ++cur;
    cout << ds[h*w-1] +cur << endl;
    return 0;
}
