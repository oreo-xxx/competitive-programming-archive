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
  int n;cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  vector<int> vec;
  int tmp = 1;
  int now = a[0];
  for(int i = 1; i < n; ++i){
    if(a[i]==now){
      ++tmp;
    }
    else{
      vec.push_back(tmp);
      tmp = 1;
      now = a[i];
    }
  }
  vec.push_back(tmp);
  if(a[0]==a[n-1]){
    vec[0] += vec.back();
  }
  if(vec[0]== 2*n){
    cout << -1 << endl;
    return 0;
  }
  int M = 0;
  for(int i = 0; i < vec.size(); ++i){
    M= max(M,vec[i]);
  }
  cout << (M-1)/2 + 1<< endl;
}
