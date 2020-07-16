#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 2;

vector<ll> dijkstra(int s, WeightedGraph & G){
  using P = pair<ll, int>;
  int n=G.size();
  vector<ll> ds(n,INF64);
  vector<ll> bs(n,-1);
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
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return bs; // 経路
  //return ds;
}


void solve() {
    ll N, M; cin >> N >> M;
    WeightedGraph G(N);
    for(int i = 0; i < M; ++i){
        ll A, B; cin >> A >> B;
        --A; --B;
        G[A].push_back({B,1});
        G[B].push_back({A,1});
    }
    auto b = dijkstra(0, G);
    for(int i = 1; i < N; ++i)
    {
        if(b[i] == -1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1; i < N; ++i)
    {
        cout << b[i]+1 << endl;
    }
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
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
