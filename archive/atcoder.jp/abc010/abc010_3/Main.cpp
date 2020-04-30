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
  ld sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  ld t,v;
  cin >> t >> v;
  ld M = t * v;
  int n; cin >> n;
  string ans = "NO";
  for(int i = 0; i < n; ++i){
    ld x,y; cin >> x >> y;
    ld d = sqrt((sx-x)*(sx-x)+(sy-y)*(sy-y));
    d += sqrt((tx-x)*(tx-x)+(ty-y)*(ty-y));
    if(d<=M){
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
}
