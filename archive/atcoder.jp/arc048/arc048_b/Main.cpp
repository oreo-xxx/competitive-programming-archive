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
struct data{
  int w,l,d;
};

int main() {
  int n;cin >>n;
  vector<pint> rh(n);
  vector<vector<int>> a(100001,vector<int> (3));
  for(int i = 0; i < n; ++i){
    int r,h;cin >>r>> h;
    --h;
    rh[i]={r,h};
    ++a[r][h];
  }
  map<pint, data> mp;
  int count = 0;
  for(int i = 100000; i >= 0; --i){
    int g = a[i][0];
    int c = a[i][1];
    int p = a[i][2];
    int total = g + c + p;
    if(total==0){continue;}
    
    mp[{i,0}].w = n-count - total +c;
    mp[{i,0}].l = count + p;
    mp[{i,0}].d = g;
    mp[{i,1}].w = n-count - total +p;
    mp[{i,1}].l = count + g;
    mp[{i,1}].d = c;
    mp[{i,2}].w = n-count - total+g;
    mp[{i,2}].l = count + c ;
    mp[{i,2}].d = p;
    count += total;
   
  }
  for(int i = 0; i < n; ++i){
    int r = rh[i].first;
    int h = rh[i].second;
    cout << mp[rh[i]].w <<" "<< mp[rh[i]].l << " " << mp[rh[i]].d -1<< endl;
  }
}
