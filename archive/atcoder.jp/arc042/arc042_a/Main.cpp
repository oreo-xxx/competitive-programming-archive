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
  int n,m;cin >>n>> m;
  vector<int> a(m);
  for(int i = 0; i < m; ++i){
    cin >>a[i];
  }
  reverse(a.begin(), a.end());
  set<int>se;
  for(int i = 0; i < m; ++i){
    if(se.count(a[i]) == 0){
      cout << a[i] << endl;
      se.insert(a[i]);
    }
  }
  for(int i = 1; i <= n; ++i){
    if(se.count(i)==0){
      cout << i<< endl;
    }
  }
}
