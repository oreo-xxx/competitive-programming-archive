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
  int x,y,k;
  cin >> x >> y >> k;
  int ans = 0;
  if(k<=y){
    ans = x+k;
  }
  else{
    ans = y + x-(k-y);
  }
  cout << ans << endl;
}
