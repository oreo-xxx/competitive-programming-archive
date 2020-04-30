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
  int k;cin >>k;
  vector<int> a(42);
  a[0]=1;a[1]=1;
  for(int i = 2; i <42; ++i){
    a[i] = a[i-1]+a[i-2]; 
  }
  cout << a[k-1]<< " " <<a[k] << endl;
}
