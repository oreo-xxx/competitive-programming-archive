#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){cin >> a[i];}
    sort(a.begin(), a.end());
    int ans = 0;
    for (int c = 0; c < n; ++c ) {
    	int r = c + 1;
    	for(int l = 0; l < c; ++l){    	    
            while ( r  < n && a[l] + a[c]  > a[r]) {
                ++r;
                ans += (c-l);               
            }        
        }      
    }
    
    cout << ans << endl;
    return 0;
}