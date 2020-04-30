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
  int h,w;cin >> h >> w;
  vector<vector<pint>> a(h,vector<pint> (w));
  vector<vector<pint>> sum(h+1,vector<pint> (w+1));
  for(int i = 0; i < h; ++i){ 
    for(int j = 0; j < w; ++j){
      if((i+j)%2==0)cin >> a[i][j].first;
      else cin >> a[i][j].second;
    }
  }
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      sum[i+1][j+1].first= sum[i+1][j].first+ sum[i][j+1].first- sum[i][j].first+ a[i][j].first;
      sum[i+1][j+1].second=sum[i+1][j].second+sum[i][j+1].second-sum[i][j].second+a[i][j].second;
    }
  }

  int ans = 0;
  for(int i = 0; i < h+1; ++i){
    for(int j = 0; j < w+1; ++j){
      //cout << sum[i][j].first << ',' << sum[i][j].second << ' ';
      for(int k = i; k < h+1; ++k){
        for(int l = j; l < w+1; ++l){
          int b= sum[k][l].first +sum[i][j].first -sum[i][l].first -sum[k][j].first;
          int w= sum[k][l].second+sum[i][j].second-sum[i][l].second-sum[k][j].second;
          if(b==w){
            //cout << b << w << endl;
            ans = max(ans,(k-i)*(l-j));
          }
        }
      }
    }
    //cout << endl;
  }
  cout << ans << endl;
}
