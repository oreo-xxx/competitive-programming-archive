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
  string s,t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  vector<int> as(n+1),bs(n+1);
  vector<int> at(m+1),bt(m+1);
  for(int i = 0; i < n; ++i){
    as[i+1]=as[i]+ (s[i]=='A');
    bs[i+1]=bs[i]+ (s[i]=='B');
  }
  for(int i = 0; i < m; ++i){
    at[i+1]=at[i]+ (t[i]=='A');
    bt[i+1]=bt[i]+ (t[i]=='B');
  }
  
  int q;cin >> q;
  
  for(int i = 0; i < q; ++i){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    --a;--c;
    int s1 = as[b]-as[a];
    int s2 = bs[b]-bs[a];
    int t1 = at[d]-at[c];
    int t2 = bt[d]-bt[c];
    s1 += 2 * s2;
    t1 += 2 * t2;
    string ans = "NO";
    if(abs(s1-t1)%3==0) ans= "YES";
    cout << ans << endl;
  }
}

