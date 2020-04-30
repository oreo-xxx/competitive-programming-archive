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
  int x1,y1,r;
  cin >> x1 >> y1 >> r;
  int x2,y2,x3,y3;
  cin >> x2 >> y2 >> x3 >> y3;
  string ans = "YES";
  if(x2 <= x1-r && x1+ r<= x3 && 
     y2 <= y1-r && y1+ r<= y3){
    ans = "NO";
  }
  cout << ans << endl;
  int d1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  int d2 = (x3-x1)*(x3-x1) + (y2-y1)*(y2-y1);
  int d3 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
  int d4 = (x2-x1)*(x2-x1) + (y3-y1)*(y3-y1);
  ans = "YES";
  if( d1 <= r*r && d2 <= r*r &&
     d3 <= r*r && d4 <= r*r){
    ans = "NO";
  }
  cout << ans << endl;
}
