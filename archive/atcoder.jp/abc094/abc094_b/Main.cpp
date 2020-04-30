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
  int n,m,x;
  cin >> n>> m>> x;
  vector<int> a(n+1);
  for(int i = 0; i < m; ++i){
    int b;cin >> b;
    ++a[b];
  }
  int t1=0,t2=0;
  for(int i = 0; i < x; ++i){
    t1+=a[i];
  }
  for(int i = x; i <= n; ++i){
    t2+=a[i];
  }
  int ans = min(t1,t2);
  cout << ans << endl;
}
