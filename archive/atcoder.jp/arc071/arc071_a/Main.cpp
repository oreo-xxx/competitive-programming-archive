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
  vector<string> s(n);
  for(int i = 0; i < n; ++i)cin >> s[i];
  vector<map<char, int> >mp(n);
  for(int i = 0; i < n; ++i){
    int m = s[i].size();
    for(int j = 0; j < m; ++j){
      ++mp[i][s[i][j]];
    }
  }
  string ans;
  for(int i = 0; i < 26; ++i){
    char c = (char)(i+'a');
    int tmp = 100;
    for(int j = 0; j < n; ++j){
      tmp = min(tmp, mp[j][c]);
    }
    for(int j = 0; j < tmp; ++j){
      ans+= c;
    }
  }
  cout << ans << endl;
}
