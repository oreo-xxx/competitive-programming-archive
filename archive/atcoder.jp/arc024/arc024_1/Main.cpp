#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n,m;cin >> n >> m;
  map<int, int> l;
  for(int i = 0; i < n; ++i){
    int a;cin >> a;
    ++l[a];
  }
  map<int, int> r;
  for(int i = 0; i < m; ++i){
    int a;cin >> a;
    ++r[a];
  }
  int ans = 0;
  for(auto it : l){
    ans += min(it.second, r[it.first]);
  }
cout << ans << endl;

}
