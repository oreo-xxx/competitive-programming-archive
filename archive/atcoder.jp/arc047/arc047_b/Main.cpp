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
  int n;cin >> n;
  vector<int> x(n), y(n);
  for(int i = 0; i < n; ++i){
    cin >> x[i] >> y[i];
  }
  int l,r,u,d;
  l = d = INF32, r = u = -INF32;
  for(int i = 0; i < n; ++i){
    int rx = x[i]-y[i];
    int ry = x[i]+y[i];
    //x[i]= rx; y[i]= ry;
    l = min(l,rx);
    r = max(r,rx);
    d = min(d,ry);
    u = max(u,ry);
  }
  int xm = r-l+1, ym = u-d+1;
  if(xm == 1 && ym == 1){
    cout << x[0]+1 << " " << x[0]+1 << endl;
    return 0;
  }
  
  int xc,yc;
  if(xm > ym){
    xc = xm/2 + l;
    yc = xm/2 + d;
  }
  else{
    xc = ym/2 + l;
    yc = ym/2 + d;
  }
  
  int xa = (xc + yc)/2;
  int ya = (yc - xc)/2;
  for(int i = -1; i <= 1; ++i){
    for(int j = -1; j <= 1; ++j){
      bool flag = true;
      int dist = abs(xa+ i -x[0]) + abs(ya+j-y[0]);
      for(int k = 1; k < n; ++k){
        int tmp = abs(xa+ i -x[k]) + abs(ya+j-y[k]);
        if(tmp != dist){
          flag=false;
          break;
        }
      }
      if(flag){
        cout << xa + i << " " << ya + j << endl;
        return 0;
      }
    }
  }
  
  if(xm > ym){
    xc = r - xm/2;
    yc = u - xm/2;
  }
  else{
    xc = r - ym/2;
    yc = u - ym/2;
  }
  xa = (xc + yc)/2;
  ya = (yc - xc)/2;
  for(int i = -1; i <= 1; ++i){
    for(int j = -1; j <= 1; ++j){
      bool flag = true;
      int dist = abs(xa+ i -x[0]) + abs(ya+j-y[0]);
      for(int k = 1; k < n; ++k){
        int tmp = abs(xa+ i -x[k]) + abs(ya+j-y[k]);
        if(tmp != dist){
          flag=false;
          break;
        }
      }
      if(flag){
        cout << xa + i << " " << ya + j << endl;
        return 0;
      }
    }
  }
}
