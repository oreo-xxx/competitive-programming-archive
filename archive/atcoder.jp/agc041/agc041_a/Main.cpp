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
  ll n, a, b;cin >> n >> a >> b;
  if((b-a)%2LL==0){
    cout << (b-a)/2LL << endl;
    return 0;
  }
  ll ans = 0;
  if(a-1<n-b){
    ans = a;
    b-=a;
    ans+=(b)/2LL;
  }
  else{
    ans= n-b;
    a+=n-b;
    ans+=(n-a+1)/2LL; 
  }
  cout << ans << endl;
}
