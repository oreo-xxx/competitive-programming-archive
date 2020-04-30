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
  int n;cin >> n;
  set<string> se;
  string prev; cin >> prev;
  se.insert(prev);
  int i = 0;
  for(i = 1; i < n; ++i){
    string s;cin >> s;
    if(se.count(s)!=0){break;}
    se.insert(s);
    if(prev.back()!=s.front()){break;}
    prev= s;
  }
  string ans;
  if(i==n){ans="DRAW";}
  else if(i%2==1){
    ans="WIN";
  }
  else{
    ans= "LOSE";
  }
  cout << ans << endl;
}
