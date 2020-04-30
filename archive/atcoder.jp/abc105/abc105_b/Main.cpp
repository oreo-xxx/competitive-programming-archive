#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; cin >> n;
    for(int i = 0; i < 26; ++i){
    	for(int j = 0; j < 16; ++j){
    	    if(4*i + 7*j == n){
    	         cout << "Yes" << endl;
                 return 0;
            }
        }
    }
    cout << "No" << endl;
}