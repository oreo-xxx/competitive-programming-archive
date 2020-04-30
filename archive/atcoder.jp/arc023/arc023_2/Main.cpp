#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int h, w, d;cin >>h >> w >> d;
  bool flag = d%2;
  vector<int>a(h+w);
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      int tmp;cin >>tmp;
      if(flag == (i+j)%2){
        a[(i+j)/2]=max(a[(i+j)/2], tmp);
      }
    }
  }
  int ans=0;
  int t =min(d/2+1, (int)a.size());
  for(int i = 0; i < t; ++i){
    ans=max(ans, a[i]);
  }
  cout << ans << endl;
}
