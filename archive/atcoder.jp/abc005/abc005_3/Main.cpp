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
	int t, n;cin >>t>> n;
  vector<pint> a(n);
  for(int i = 0; i < n; ++i){
    cin >>a[i].first;
    a[i].second= a[i].first+t;
  }
  int m;cin >>m;
  if(n<m){
    cout << "no" << endl;
    return 0;
  }
  int i=0;
  for(int j = 0; j < m; ++j){
    int b;cin >>b;
    bool flag = false;
    while(i<n){
      if(a[i].first <= b && b <= a[i].second){
        flag = true;
        ++i;
        break;
      } 
      ++i;
    }
    if(flag){continue;}
    else{
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
