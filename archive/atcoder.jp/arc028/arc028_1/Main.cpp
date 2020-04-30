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
  int n,a,b;cin >> n >> a >> b;
  string ans= "Ant";
  for(int i = 0; i < 1000; ++i){
    if(i%2==0)n-=a;
    else      n-=b;
    if(n<=0){
      if(i%2==1)ans = "Bug";
      break;
    }
  }
  cout << ans << endl;
  
}
