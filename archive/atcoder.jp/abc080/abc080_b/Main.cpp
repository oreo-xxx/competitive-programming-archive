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
   int n;cin >> n;
  int org = n;
  int tmp = 0;
  while(n>0){
    tmp+= n%10;
    n /= 10;
  }
  string ans = "No";
  if(org%tmp == 0)ans = "Yes";
  cout << ans << endl;
}
