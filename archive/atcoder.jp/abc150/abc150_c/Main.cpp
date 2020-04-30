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
  vector<int> a(n), p(n), q(n);
  iota(a.begin(),a.end(),1);
  for(int i = 0; i < n; ++i) cin >> p[i];
  for(int i = 0; i < n; ++i) cin >> q[i];
  int t1, t2;
  int cnt = 0;
  do{
    if(a==p)t1 = cnt;
    if(a==q)t2 = cnt;
    ++cnt;
  }while(next_permutation(a.begin(), a.end()) );
  cout << abs(t1-t2) << endl;
}
