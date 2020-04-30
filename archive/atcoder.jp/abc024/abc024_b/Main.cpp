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
  int n,t; cin >> n >> t;
  int prev = 0, ans = 0;
  for(int i = 0; i < n; ++i){
    int a; cin >> a;
    ans += max(0, a+t - max(a,prev));
    prev = max(prev, a+t);
  }
  cout << ans << endl;
}
