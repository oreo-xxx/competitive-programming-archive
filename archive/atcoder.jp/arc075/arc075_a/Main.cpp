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
  ll n;cin >> n;
  vector<ll> a(n);
  ll sum= 0;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    sum+= a[i];
  }
  sort(a.begin(), a.end());
  ll omit = 0;
  if(sum%10==0){
    for(int i = 0; i < n; ++i){
      if(a[i]%10 != 0){
        omit = a[i];
        break;
      }
    }
    if(omit!=0){
      sum-=omit;
    }
    else{
      sum=0;
    }
  }
  cout << sum << endl;
}
