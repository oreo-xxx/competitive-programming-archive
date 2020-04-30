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

ll h,w,K;
void func(vector<int>& dst, vector<int>& src){
  for(int i = 0; i < w; ++i){
    dst[i] += src[i];
    if(dst[i]>K)dst[0]= -1;
  }
}
int main(){
  cin >> h >> w >> K;
  vector<string> a(h);
  for(int i = 0; i < h; ++i)cin >> a[i];
  Graph s(h,vector<int>(w) );
  for(int i = 0; i < h; ++i){
    for(int j = 0; j < w; ++j){
      if(a[i][j]=='1')s[i][j]=1;
    }
  }
  ll ans = INF;
  for(int i = 0; i < (1LL<<(h-1)); ++i){
    bitset<10> bs (i);
    ll cnt = bs.count();
    if(cnt>ans)continue;
    ll sz = cnt +1;
    
    Graph vec(sz,vector<int>(w));
    ll now = 0;
    bool g = false;
    func(vec[now], s[0]);
    for(int j = 0; j < h-1; ++j){
      if(bs[j])++now;
      func(vec[now], s[j+1]);
      if(vec[now][0]==-1)g=true;
    }
    if(g)continue;
    vector<ll> tmp(sz);
    for(int j = 0; j < w; ++j){
      bool f = true;
      for(int k = 0; k < sz; ++k){
        tmp[k]+= vec[k][j];
        if(tmp[k]>K) f = false;
      }
      if(f)continue;
      ++cnt;
      for(int k = 0; k < sz; ++k){
        tmp[k]= vec[k][j];
      }
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;
}
