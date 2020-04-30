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
  string s;cin >> s;
  int n= s.size();
  int m= n/2; 
  bool f=true;
  for(int i = 0; i < m; ++i){
    if(s[i] != s[n-1-i]){
      f = false;
      break;
    }
  }
  string ans= "NO";
  if(f){ans= "YES";}
  cout << ans << endl;
}
