#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
     int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){cin >> a[i];}
  
   ll sum = 0, prev =0;
   ll ans1 =0, ans2 =0;
   for(int i = 0; i < n; ++i){
     sum += a[i];
     if(i % 2 ==0){
       if(sum <= 0){
         ans1 += abs(sum)+1;
         sum = 1;
       }
     }
     else{
       if(sum>=0){
         ans1 += abs(sum)+1;
         sum = -1;
       }
     }
   }
  sum=0;
   for(int i = 0; i < n; ++i){
     sum += a[i];
     if(i % 2 !=0){
       if(sum <= 0){
         ans2 += abs(sum)+1;
         sum = 1;
       }
     }
     else{
       if(sum>=0){
         ans2 += abs(sum)+1;
         sum = -1;
       }
     }       
   }
   ll ans = min(ans1, ans2);
   cout << ans << endl;
}