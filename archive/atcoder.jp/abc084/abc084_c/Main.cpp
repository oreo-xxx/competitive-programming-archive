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

int main() {
  ll n;cin >>n;
  vector<ll> c(n), s(n), f(n);
  for(int i = 0; i <n; ++i){
    cin >>c[i] >> s[i]>> f[i];
  }
  
  for(int i = 0; i < n; ++i){
    int now=0;
    for(int j = i; j < n-1; ++j){
      int dept = s[j];
      if(now>s[j])dept=((now+f[j]-1)/f[j])* f[j];
      now=dept+c[j];
    }
    cout << now << endl;
  }
}
