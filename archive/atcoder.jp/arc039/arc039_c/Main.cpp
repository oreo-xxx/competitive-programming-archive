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

map<vector<int>, pint> mp;

int dx[] {1,0,-1,0};
int dy[] {0,-1,0,1};

void update(int x, int y){
  for(int i = 0; i < 4; ++i){
    if(!mp.count({x,y,i}))mp[{x,y,i}]={x+dx[i], y+dy[i]};
  }
  for(int i = 0; i < 4; ++i){
    int j = (i+2)%4;
    pint p = mp[{x,y,i}];
    mp[{p.first, p.second, j}]=mp[{x,y,j}];
  }
}

int main(){
  int k; string s;
  cin >> k >> s;
  int x = 0, y = 0;
  update(x,y);
  for(int i = 0; i < k; ++i){
    pint p;
    if(s[i]=='R')p=mp[{x,y,0}];
    if(s[i]=='D')p=mp[{x,y,1}];
    if(s[i]=='L')p=mp[{x,y,2}];
    if(s[i]=='U')p=mp[{x,y,3}];
    x= p.first; y = p.second;
    update(x,y);
  }
  cout << x << " " << y << endl;
}
