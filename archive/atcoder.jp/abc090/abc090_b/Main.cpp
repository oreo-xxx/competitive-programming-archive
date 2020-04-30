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
  int a,b;cin >> a >> b;
  int ans = 0;
  for(int i = a; i <= b; ++i){
    string s = to_string(i);
    int n = s.size();
    bool f = true;
    for(int j = 0; j < n; ++j){
      if(s[j]!=s[n-1-j]){
        f = false;
        break;
      }
    }
    if(f)++ans;
  }
  cout << ans << endl;
}
