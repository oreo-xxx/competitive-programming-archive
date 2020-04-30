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
  ll n; cin >> n;
  vector<pair<ld,ld>> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second ;
  }
  ll c=0,d=0;
  for(int i = 0; i < n; ++i){
    vector<ld> arg;
    for(int j = 0; j < n; ++j){
      if(i==j)continue;
      ld x = a[j].first-a[i].first;
      ld y = a[j].second -a[i].second ;
      arg.push_back(atan2l(y,x));
    }
    sort(arg.begin(), arg.end());
    
    for(int j = 0; j < n-1; ++j){
      ld a1 = arg[j]+M_PI/2.0;
      ld a2 = arg[j]+M_PI*1.5;
      ll m1 = lower_bound(arg.begin(), arg.end(), a1)-arg.begin();
      ll m2 = lower_bound(arg.begin(), arg.end(), a2)-arg.begin();
      d+= m2-m1;
      if(m1<n-1 && abs(arg[m1]-a1)<1e-12){
        ++c;
        --d;
      }
      if(m2<n-1 && abs(arg[m2]-a2)<1e-12 ){
        ++c;
      }
    }
  }
  ll sum = n*(n-1)*(n-2)/6;
  cout << sum-c-d << " " << c << " " << d << endl;
}
