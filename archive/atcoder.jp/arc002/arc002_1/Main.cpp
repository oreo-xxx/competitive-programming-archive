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
  int y;cin >> y;
  string ans = "NO";
  if(y%400==0){
    ans = "YES";
  }
  else if(y%4==0 && y%100!=0){
    ans = "YES";
  }
  cout << ans << endl;
}
