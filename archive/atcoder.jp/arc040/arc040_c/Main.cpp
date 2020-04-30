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
  int n; cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; ++i)cin >> s[i];
  
  int ans = 0;
  for(int sy = 0; sy < n; ++sy){
    int tx = -1;
    for(int x = 0; x < n; ++x){
      if(s[sy][x]!='o'){
        s[sy][x]= 'o';
        tx = x;
      }
    }
    if(tx==-1)continue;
    
    int gy = n;
    for(int y = sy+1; y < min(n,sy+2); ++y){
      bool f = false;
      for(int x = tx; x < n; ++x){
        if(s[y][x]!='o'){
          s[y][x]='o';
          f = true;
        }
      }
      if(f)break;
    }
    ++ans;
  }
  cout << ans << endl;
}
