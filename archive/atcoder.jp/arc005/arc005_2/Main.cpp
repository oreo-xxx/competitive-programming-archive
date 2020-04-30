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

string s;

bool check(char c){
  for(int i = 0; i < s.size(); ++i){
    if(s[i]==c) return true;
  }
  return false;
}

int main() {
  int x,y;cin >> x >> y;
  --x;--y;
  cin >> s;
  int n = 9;
  vector<string> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  for(int i = 0; i < 4; ++i){
    int h = y,w = x;
    if(check('R')){
      w += i;
      if(w>8){
        int res = w - 8;
        w = 8 - res;
      }
    }
    else if(check('L')){
      w -= i;
      if(w<0){
        w = -1 * w;
      }
    }
    
    if(check('D')){
      h += i;
      if(h>8){
        int res = h-8;
        h = 8 - res;
      }
    }
    else if(check('U')){
      h -= i;
      if(h<0){
        h = -1 * h;
      }
    }
    cout << a[h][w];
  }
  cout << endl;
}
