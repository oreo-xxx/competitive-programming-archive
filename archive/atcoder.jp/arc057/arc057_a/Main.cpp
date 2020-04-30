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
  ll a,k;cin >> a>> k;
  ll M=2e12;
  if(k==0){
    cout << M-a << endl;
    return 0;
  }
  ll ans=0;
  while(a<M){
    a+= a*k+1;
    ++ans;
  }
  cout << ans << endl;
}
