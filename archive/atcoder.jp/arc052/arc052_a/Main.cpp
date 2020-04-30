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
  string s;
  cin >> s;
  int n= s.size();
  string ans;
  for(int i = 0; i < n; ++i){
    if('0'<=s[i]&&s[i]<='9'){
      ans += s[i];
      if(i+1<n && '0'<=s[i+1] && s[i+1]<='9'){
        ans += s[i+1];
      }
      break;
    } 
  }
  cout << ans << endl;
}
