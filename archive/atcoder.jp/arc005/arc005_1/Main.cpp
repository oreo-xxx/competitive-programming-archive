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

int check(vector<string>& a, string t){
  int n = a.size();
  int ans = 0;
  for(int i = 0; i < n-1; ++i){
    if(a[i]==t){
      ++ans;
    }
  }
  if(a.back()== t+'.'){
    ++ans;
  }
  return ans;
}

int main(){
  int n; cin >> n;
  vector<string> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  string t1 = "TAKAHASHIKUN";
  string t2 = "Takahashikun";
  string t3 = "takahashikun";
    
  int ans = check(a, t1);
  ans += check(a, t2);
  ans+= check(a,t3);
  cout << ans << endl;
  
}
