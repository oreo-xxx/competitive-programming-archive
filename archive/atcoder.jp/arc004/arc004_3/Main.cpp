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

vector<ll> getprime(ll n){
  vector<ll> ans;
  for(ll i = 2; i*i <= n; ++i){
    if(n%i!=0)continue;
    while(n%i==0)n /= i;
    ans.push_back(i);
  }
  if(n!=1)ans.push_back(n );
  return ans;
}

void kiyaku(ll& x, ll& y, vector<ll>& p){
  ll m = p.size();
  for(ll i = 0; i < m; ++i){
    while(x%p[i]==0 && y%p[i]==0){
      x /= p[i];
      y /= p[i];
    }
  }
}

int main(){
  ll x = 0, y = 0;
  scanf("%lld/%lld", &x, &y);
  ll g = __gcd(x,y);
  x /= g;
  y /= g;
  ll tn = 2LL*(x/y);
  bool f = true;
  for(ll i = -10; i < 11; ++i){
    ll N = tn + i;
    if(x%y!=0 && N%y!=0)continue;
    ll M = N*(N+1)/2LL - N/y*x;
    if(0<N && 0<M && M <= N){
      f = false;
      cout << N << " " << M << endl;
    }
  }
  if(f)cout << "Impossible" << endl;
}
