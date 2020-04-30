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
  int n; cin >>n;
  int m = -1;
  for(int i = 0; i <= n; ++i){
    if(i*(i+1)/2==n){
      m=i;
      break;
    }
  }
  if(m==-1){
    cout << "No" << endl;
    return 0;
  }
  vector<vector<int> > a(m+1, vector<int> (m));
  int num =1;
  for(int i = 0; i < m+1; ++i){
    for(int j = i; j < m; ++j){
      a[i][j]=a[j+1][i]=num;
      ++num;
    }
  }
  cout << "Yes" << endl;
  cout << m+1 << endl;
  for(int i = 0; i < m+1; ++i){
    cout << m << " ";
    for(int j = 0; j < m-1; ++j){
      cout << a[i][j] << " ";
    }
    cout << a[i][m-1] << endl;
  }
}
