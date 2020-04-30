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
  int a,b;cin >> a >> b;
  int d = abs(b - a);
  int ans = d / 10;
  d %= 10;
  if(d == 9 || d == 8){
    ans += 1+ (10-d); 
  }
  else if(2<d && d<8){
    ans += 1+ abs(5-d); 
  }else{
    ans += d;
  }
  cout << ans << endl;
}
