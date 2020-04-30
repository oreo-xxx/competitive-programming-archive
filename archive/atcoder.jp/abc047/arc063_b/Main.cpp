#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){cin >> a[i];}
    
    int profit = 0, ans = 1;
    int right = 0;
    for (int left = 0; left < n; ) {
    	int tmp = -1;
        while (right < n && (right == left || a[right] > a[left])) {
            ++right;
            tmp = max(tmp, a[right]-a[left]);
        }
        if(tmp > profit){
        	profit = tmp;
        }
        else if(tmp ==profit ){++ans;}
        else{
        }
        left =right;
        
    }
   
    cout << ans << endl;
    return 0;
}