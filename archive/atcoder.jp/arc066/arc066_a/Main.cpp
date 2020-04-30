#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>;
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  int n; cin >>n;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    int a;cin >>a;
    ++mp[a];
  }
  if(n%2==0){
    int i=1;
    for(auto it : mp){
      if(it.first !=i ||  it.second!=2){
        cout << 0 << endl;
        return 0;
      }
      i+=2;
    }
  }
  else{
    int i =2;
    for(auto it : mp){
      if(it.first==0&& it.second==1){
        continue;
      }
      if(it.first!=i ||  it.second!=2){
        cout << 0 << endl;
        return 0;
      }
      i+=2;
    }
  }
  ll ans = modpow(2, n/2, MOD);
  cout << ans << endl;
}
