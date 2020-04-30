#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100; b *= 100;
    int w = 0, s = 0;
    P ans = {0, a};
    for(int i = 0; i <= 30; ++i){
       w = a*i; s = 0;
       if(w+s>f){break;}
       for(int j = 0; j <= 30; ++j){
       	w = i * a +  j * b;
           if(w+s>f){break;}
           if(w == 0){break;}
           for(int k = 0; k <= f/c+1; ++k){
           	s = k * c;
               if(w+s>f){break;}
               if(100 * s > (w)*e){break;}
               for(int l = 0; l <= f/d+1; ++l){
               	s = k * c + l * d;
                   if(w+s>f){break;}
                   if(100 * s > (w)*e){break;}
                   if(ans.first *(s+w)<s*ans.second){ans = {s, s+w};}
        
              }
           }
       }
    }    

    cout << ans.second << " " << ans.first  << endl;
    
    return 0;
}