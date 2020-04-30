#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const ll MAXN = 8020;

int main(){
  string s; cin >> s;
  int x,y; cin >> x >> y;

  vector<int> t;
  int cnt = 0;
//文字列を変形する
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'T'){
      if(cnt != 0) t.push_back(cnt);
      t.push_back(0);
      cnt = 0;
    }else{
      cnt++;
      if(i == s.size()-1) t.push_back(cnt);
    }
  }

  bool dp_x[MAXN][MAXN*2] = {false}, dp_y[MAXN][MAXN*2] = {false};
  dp_x[0][8000] = true;
  dp_y[0][8000] = true;

  bool flag = false;
  bool xy = true; // trueならx軸について見ている
  int cnt_x = 0,cnt_y = 0;
  int prev_x =0, prev_y =0;
  for(int i = 0; i < t.size(); i++){
    if(t[i] == 0){
      xy  = !xy;
    }else if(xy){
      cnt_x++;
      for(int j = 0; j < MAXN*2; j++){
        if(dp_x[cnt_x-1][j]){
          if(j+t[i] < MAXN*2) dp_x[cnt_x][j+t[i]] = true;
          if(j-t[i] >= 0 && flag) dp_x[cnt_x][j-t[i]] = true;
        }
      }
    }else if(!xy){
      cnt_y++;
      for(int j = 0; j < MAXN*2; j++){
        if(dp_y[cnt_y-1][j]){
          if(j+t[i] < MAXN*2) dp_y[cnt_y][j+t[i]] = true;
          if(j-t[i] >= 0) dp_y[cnt_y][j-t[i]] = true;
        }
      }
    }

    if(!flag) flag = true;
  }

  cout << ((dp_x[cnt_x][x+8000] && dp_y[cnt_y][y+8000]) ? "Yes" : "No") << endl;

  return 0;
}