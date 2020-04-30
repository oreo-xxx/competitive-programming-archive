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
  ll n; cin >>n;
  vector<int> p(n);
  for(int i = 0; i < n; ++i)cin >>p[i];
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; ++i){
    a[i]=30000*(i+1);
    b[i]+=30000*(n-i);
    b[p[i]-1]+=i;
  }
  for(int i = 0; i < n; ++i){
    cout << a[i];
    if(i==n-1){cout << endl;}
    else{cout << " ";}
  }
  for(int i = 0; i < n; ++i){
    cout << b[i];
    if(i==n-1){cout << endl;}
    else{cout << " ";}
  }
}
