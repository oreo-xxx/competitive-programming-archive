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
  int n;cin >>n;
  vector<int> a(6);
  for(int i = 0; i < n; ++i){
    float M,m;cin >>M>> m;
    if(M>=35.0){++a[0];}
    else if(M>=30.0){++a[1];}
    else if(M>=25.0){++a[2];}
    if(m>=25.0){++a[3];}
    if(M>=0.0&&m<0){++a[4];}
    if(M<0){++a[5];}
  }
  for(int i = 0; i < 5; ++i){  
    cout << a[i] << " ";
  }
  cout << a[5] << endl;
}
