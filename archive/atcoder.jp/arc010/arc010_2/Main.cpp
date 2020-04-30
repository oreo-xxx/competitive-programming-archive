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


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

int main() {
  vector<int> dom {31,29,31,30,31,30,31,31,30,31,30,31};
  vector<int> sum(13);
  for(int i = 0; i < 12; ++i){
    sum[i+1]=sum[i]+dom[i];
  }
  vector<int> holiday(366);
  for(int i = 0; i < 366; ++i){
    if(i%7==0 || i%7==6) holiday[i] = 1;
  }
  int n;cin >> n;
  for(int i = 0; i < n; ++i){
    string s;cin >> s;
    vector<string> md = split(s,'/');
    int m = stoi(md[0]);
    int d = stoi(md[1]);
    int doy = sum[m-1]+d-1;
    if(holiday[doy]==0){holiday[doy]= 1;}
    else{
      for(int j = 0; j +doy< 366; ++j){
        if(holiday[j+doy]==0){
          holiday[j+doy]=1;
          break;
        }
      }
    }
  }
  int ans = 0, tmp = 0;
  for(int i = 0; i < 366; ++i){
    if(holiday[i]==1){++tmp;}
    else{tmp=0;}
    ans = max(ans,tmp);
  }
  cout << ans << endl;
}
