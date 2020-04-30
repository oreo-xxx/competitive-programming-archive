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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int l = a+b;
  int r = c+d;
  string ans = "Balanced";
  if(l>r)ans = "Left";
  if(l<r)ans = "Right";
  cout << ans << endl;
}
