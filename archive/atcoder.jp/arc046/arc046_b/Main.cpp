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
  int n,a,b;
  cin >> n >> a >> b;
  if(a>= n){
    cout << "Takahashi" << endl;
    return 0;
  }
  string ans = "Takahashi";
  if(a==b){
    if(n%(a + 1)== 0)ans = "Aoki";
  }
  else{
    if(b>a)ans = "Aoki";
  }
  cout << ans << endl;
}
