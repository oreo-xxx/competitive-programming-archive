#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = pair<int, ll>;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n,m;  cin >> n>> m;
  vector<ll> a(n+1);
  for(int i = 0; i < m; ++i){
    int l,r;cin >>l>> r;
    --l;
    ++a[l];--a[r];
  }
  for(int i = 0; i < n-1; ++i){
    a[i+1]+=a[i];
  }
  for(int i = 0; i < n; ++i){
    cout << a[i]%2;
  }
  cout << endl;
}
