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
  ld l,x,y,s,d;
  cin >> l >> x >> y >> s >> d;
  ld g = d-s;
  if(g<0)g+=l;
  ld ans = g/(x+y);
  if(x<y){
    g = s-d;
    if(g<0) g+= l;
      ans = min(ans,g/(y-x));
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
}
