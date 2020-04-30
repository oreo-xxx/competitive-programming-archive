#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main(){
    int a,b; cin >>a >> b; --a; --b;
    int H = 100; int W = 100;
    vector<string > field(H);
    
    for(int i = 0; i < H/2; ++i){
  	  for(int j = 0; j < W; ++j){
  	      if(a>0 && i%2==0 && j%2==0){
  	          field[i] += ".";
                --a;
            }
            else{
            	 field[i] += "#";
            }
        }
    }
    for(int i = H-1; i >= H/2; --i){
  	  for(int j = 0; j < W; ++j){
  	      if(b>0 && i%2!=0 && j%2==0){
  	          field[i] += "#";
                --b;
            }
            else{
            	 field[i] += ".";
            }
        }
    }
    cout << H << " " << W<< endl;
    for(int i = 0; i < H; ++i){
        cout << field[i] << endl;  
    }
    
    return 0;
}