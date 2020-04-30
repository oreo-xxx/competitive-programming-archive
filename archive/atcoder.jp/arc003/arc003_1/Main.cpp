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
  string s;cin >> s;
  for(int i = 0; i < n; ++i){
    int c = s[i]-'A';
    ++a[c];
  }
  ld ans = 0;
  for(int i = 0; i < 4; ++i){
    ans += (4-i)*a[i];
  }
  ans = ans/(ld)n;
  cout << fixed << setprecision(10)<< ans << endl;
}
