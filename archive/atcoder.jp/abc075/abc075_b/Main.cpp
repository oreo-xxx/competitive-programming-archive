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
  int h,w;cin >> h >> w;
  vector<vector<char>> s(h+2,vector<char>(w+2));
  for(int i = 0; i < h; ++i){
    string t;cin >> t;
    for(int j = 0; j < w; ++j){
      s[i+1][j+1]=t[j];
    }
  }
  for(int i = 1; i <= h; ++i){
    for(int j = 1; j <= w; ++j){
      if(s[i][j]=='#'){
        cout << '#';
        continue;
      }
      int ans = 0;
      if(s[i-1][j-1]=='#')++ans;
      if(s[i-1][j]=='#')++ans;
      if(s[i-1][j+1]=='#')++ans;
      if(s[i][j-1]=='#')++ans;
      if(s[i][j+1]=='#')++ans;
      if(s[i+1][j-1]=='#')++ans;
      if(s[i+1][j]=='#')++ans;
      if(s[i+1][j+1]=='#')++ans;
      cout << ans;
    }
    cout <<  endl;
  }
}
