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
  int n,m;cin >> n>> m;
  set<int>se;
  for(int i = 0; i < n; ++i){
    int a;cin >> a;
    se.insert(a);
  }
  int ans= 0;
  for(int i = 0; i < m; ++i){
    int b;cin >> b;
    if(se.count(b)!=0){
      ++ans;
    }
    se.insert(b);
  }
  ld s = (ld)se.size();
  ld u = (ld)ans;
  cout << setprecision(10) << u/s << endl;
    
}
