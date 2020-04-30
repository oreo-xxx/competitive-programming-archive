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
  ld a,b;cin >> a >> b;
  string ans = "N";
  for(int i = 0; i < 16; ++i){
    if(112.5 + i*225<=a & a < 337.5 + i*225){
      if(i==0)ans="NNE";
      if(i==1)ans="NE";
      if(i==2)ans="ENE";
      if(i==3)ans="E";
      if(i==4)ans="ESE";
      if(i==5)ans="SE";
      if(i==6)ans="SSE";
      if(i==7)ans="S";
      if(i==8)ans="SSW";
      if(i==9)ans="SW";
      if(i==10)ans="WSW";
      if(i==11)ans="W";
      if(i==12)ans="WNW";
      if(i==13)ans="NW";
      if(i==14)ans="NNW";
      break;
    }
  }
  b /= 60.0;
  b *= 10.0;
  b = round(b);
  //cout << b << endl;
  int ans2;
  if(b<3) ans2 = 0;
  else if(b<16) ans2 = 1;
  else if(b<34) ans2 = 2;
  else if(b<55) ans2 = 3;
  else if(b<80) ans2 = 4;
  else if(b<108) ans2 = 5;
  else if(b<139) ans2 = 6;
  else if(b<172) ans2 = 7;
  else if(b<208) ans2 = 8;
  else if(b<245) ans2 = 9;
  else if(b<285) ans2 = 10;
  else if(b<327) ans2 = 11;
  else ans2 = 12;
  
  if(ans2==0) ans = "C";

  cout << ans << " " << ans2 << endl;
}
