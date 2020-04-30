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
  ll n;cin >>n;
  vector<int> a(n), idx(n), ans(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];  --a[i];
    idx[a[i]]=i;
  }
  for(int i = 0; i < n-1; ++i){
    if(idx[i]<idx[i+1])ans[i]=1;
  }
  int j=0, len = 0;
  for(int i = 0; i < n; ++i){
    if(ans[i]==1){++j;}
    else{len=max(len, j);j=0;}
  }
 
  cout << n-len -1<< endl;
}
