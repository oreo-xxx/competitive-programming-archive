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
  int a,b,c; cin >> a >> b >> c;
  int ans = 0;
  if(a==b)ans = c;
  else if(a==c)ans = b;
  else if(b==c)ans = a;
  cout << ans << endl;
}
