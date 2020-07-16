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
  int a,b; cin >> a >> b;
  if(a==1) a= 14;
  if(b==1) b= 14;
  string ans = "Draw";
  if(a>b)ans = "Alice";
  if(b>a)ans = "Bob";
  cout << ans << endl;
}
