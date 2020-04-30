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
  int n,l;cin >> n >> l;
  vector<string> a(l);
  getline(cin, a[0]);
  for(int i = 0; i < l; ++i){
    getline(cin, a[l-1-i]);
  }
  for(int i = 0; i < l; ++i){
     // cout << a[i]<< endl;
  }
  string s;
  getline(cin,s);
  int m = 2 * n - 1;
  int idx= 0;
  for(int i = 0; i < m; ++i){
    if(s[i]=='o'){idx = i; break;}
  }
  
  for(int i = 0; i < l; ++i){
    //cout << idx << endl;
    if(idx != 0   && a[i][idx-1]=='-')idx -= 2;
    else if(idx != m-1 && a[i][idx+1]=='-')idx += 2;
  } 
  int ans = (idx)/2 + 1;
  cout << ans << endl;
}

