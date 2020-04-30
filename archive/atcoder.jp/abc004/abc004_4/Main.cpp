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

int calc(int l, int r, int c){
  int ret = 0;
  for(int i = l; i <= r; ++i){
    ret += abs(i-c);
  }
  return ret;
}
int main(){
  int R,G,B;
  cin >> R >> G >> B;
  int ans = INF32;
  for(int l2 = -300; l2 < 300; ++l2){
    int r2 = l2 + G - 1;
    int r1 = min(-100+(R-1)/2, l2-1);
    int l1 = r1 - R + 1;
    int l3 = max(100-(B-1)/2, r2+1);
    int r3 = l3 + B-1;
    int tmp = calc(l1,r1,-100);
    tmp += calc(l2,r2,0);
    tmp += calc(l3,r3,100);
    ans = min(tmp,ans);
  }
  cout << ans << endl;
}
