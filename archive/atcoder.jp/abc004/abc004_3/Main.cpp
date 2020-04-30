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
  string s = "123456";
  int n;cin >> n;
  n %= 30;
  for(int i = 0; i < n; ++i){
    int i1 = i%5;
    int i2 = i%5+ 1;
    swap(s[i1], s[i2]);
  }
  cout << s << endl;
}
