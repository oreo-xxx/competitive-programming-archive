#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n,m,p,q,r;
  cin >> n >> m >> p >> q >> r;
  map<int, vector<pint>> mp;
  for(int i = 0; i < r; ++i){
    int x,y,z;cin >> x >> y >> z;
    mp[x-1].push_back({y-1, z});
  }
  int ans = 0;
  for(int i = 0; i < (1<<n); ++i){
    vector<int> v;
    for(int j = 0; j < n; ++j){
      if( i&(1<<j) ) v.push_back(j);
    }
    if(v.size()!= p)continue;
    vector<int> b(m);
    for(int j = 0; j < p; ++j){
      for(auto it : mp[v[j]]){
        b[it.first] += it.second;
      }
    }
    sort(b.begin(), b.end(), greater<int>());
    int tmp = 0;
    for(int j = 0; j < q; ++j){
      tmp += b[j];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
