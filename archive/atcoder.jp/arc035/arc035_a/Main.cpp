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
  string s;cin >> s;
  int n = s.size();
  string ans = "YES";
  for(int i = 0; i < n/2; ++i){
    int j = n-1-i;
    if(s[i]==s[j]||s[i]=='*'||s[j]=='*'){
      continue;
    }
    else {
      ans = "NO";
      break;
    }
  }
  cout << ans << endl;
}
