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
  vector<int> a(2402);
  for(int i = 0; i < n; ++i){
    int l,r; scanf("%d-%d",&l, &r);
    l = l - l % 5;
    if(r%5 != 0) r = r + (5-r%5);
    if(r%100==60) r+= 40;
    for(int i = l; i <= r; ++i){
      a[i] = 1;
    }
  }
  bool f = false;
  int t1,t2;
  for(int i = 0; i < 2402; ++i){
    if(!f){
      if(a[i]== 1){
        f = true;
        t1= i;
      }
    }
    else{
      if(a[i]==0){
        f = false;
        printf("%04d-%04d\n",t1,i-1);
      }
    }
  }
}
