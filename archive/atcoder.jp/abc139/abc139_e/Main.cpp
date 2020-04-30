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
  Graph a(n, vector<int> (n-1));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n-1; ++j){
      cin >> a[i][j];--a[i][j];
    }
  }
  vector<int> idx(n);
  queue<int> q;
  for(int i = 0; i < n; ++i)q.push(i);
  
  int ans = 0;
  bool f = true;
  while(f){
    f = false;
    ++ans;
    unordered_set<int> se;
    queue<int> q2;
    while (q.size()){
      int i = q.front(); q.pop();
      if(se.count(i))continue;
      if(idx[i]==n-1)continue;
      int t = a[i][idx[i]];
      if(se.count(t))continue;
      if(idx[t]==n-1)continue;
      if(a[t][idx[t]]==i){
        f = true;
        se.insert(i);
        se.insert(t);
        ++idx[i];++idx[t];
        q2.push(i); q2.push(t);
      }
    }
    swap(q,q2);
  }
  for(int i = 0; i < n; ++i){
    if(idx[i]!=n-1)ans = 0;
  }
  cout << ans-1 << endl;
}
