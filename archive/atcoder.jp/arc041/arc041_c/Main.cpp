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
  ll n,L;cin >> n >> L;
  vector<char> d(n);
  vector<ll> x(n);
  for(int i = 0; i < n; ++i)cin >> x[i]>> d[i];
  
  if(d.front()=='L'){
    d.insert(d.begin(),'R');
    x.insert(x.begin(),0);
  }
  if(d.back()== 'R'){
    d.insert(d.end(),'L');
    x.insert(x.end(),L+1);
  }
  
  n = d.size();
  ll ans = 0;
  vector<ll> rs,ls,ds;
  for(int i = 0;;){
    ll cnt = 0;
    ll r = i;
    while(d[i]=='R'){
      ++i;++cnt;
    }
    for(int j = 1; j < cnt; ++j){
      ans+= x[i-1]-x[i-1-j]-j;
    }
    r = i;
    ll tmp = x[r]-x[r-1]-1;
    rs.push_back(cnt);
    ds.push_back(tmp);
    
    cnt = 0;
    while(i<n && 'L'==d[i]){
      ++i; ++cnt;
    }
    for(int j = 1; j < cnt; ++j){
      ans += x[r+j]-x[r]-j;
    }
    ls.push_back(cnt);
    if(i==n)break;
  }
  int m = ds.size();
  for(int i = 0; i < m; ++i){
    ans += ds[i]*max(ls[i],rs[i]);
  }
  cout << ans << endl;
}
