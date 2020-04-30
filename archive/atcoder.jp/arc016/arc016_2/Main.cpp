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
  vector<string> a(n);
  for(int i = 0; i < n; ++i){cin >> a[i];}
  int ans = 0;
  for(int i = 0; i < 9; ++i){
    bool flag= false;
    for(int j = 0; j < n; ++j){
      if(flag){
        if(a[j][i]=='o'){
          continue;
        }
        else{
          flag = false;
          ++ans;
          if(a[j][i]=='x'){++ans;}
        }
      }
      else{
        if(a[j][i]=='o'){
          flag= true;
        }
        if(a[j][i]== 'x'){
          ++ans;
        }
      }
    }
    if(flag){++ans;}
  }
  
  cout << ans << endl;
}
