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

int main(){
  int n; cin >> n;
  set<int> se;
  int M=0;
  for(int i = 0; i < n; ++i){
    int a;cin >> a;
    if(a>=3200)++M;
    else{
      se.insert(a/400);
    }
  }
  int m = se.size();
  cout << max(1,m) << " " << m + M << endl;
}
