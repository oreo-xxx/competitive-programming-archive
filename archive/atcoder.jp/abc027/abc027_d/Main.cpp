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
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n+1), b(n+1);
  for(int i = 0; i < n; ++i){
    if(s[i]=='+') a[i+1]= a[i]+1;
    else a[i+1]=a[i];
    if(s[i]=='-') b[i+1]= b[i]+1;
    else b[i+1]=b[i];
  }
  vector<int> v;
  for(int i = 0; i < n; ++i){
    if(s[i]=='M')v.push_back((a[n]-a[i])-(b[n]-b[i]));
  }
  sort(v.begin(), v.end());
  int m = v.size();
  int ans = 0;
  for(int i = 0; i < m/2; ++i){
    ans-= v[i];
  }
  for(int i = m/2; i < m; ++i){
    ans+= v[i];
  }
  cout << ans << endl;
}
