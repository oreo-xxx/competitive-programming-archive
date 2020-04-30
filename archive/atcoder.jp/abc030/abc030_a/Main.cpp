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
  int a,b,c,d;cin >> a >> b >> c >> d;
  int t = c*b; int s = a*d;
  string ans = "AOKI";
  if(t>s)ans = "TAKAHASHI";
  if(t==s)ans = "DRAW";
  cout << ans << endl;
}
