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
  int n = stoi(s);
  bool f = false;
  if(n%3==0)f = true;
  for(int i = 0; i < (int)s.size(); ++i){
    if(s[i]=='3')f = true;
  }
  string ans = "NO";
  if(f)ans = "YES";
  cout << ans << endl;
}
