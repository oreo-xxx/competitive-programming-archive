#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int  n;cin >> n;
	vector<int> a(n), b(n-1);
	for(int i = 0; i < n-1; ++i){cin >> b[i];}
	a[0] = a[1] = b[0]; 
    a[n-1]=b[n-2];
     for(int i = 1; i < n-1; ++i){
    	a[i]=min(b[i-1], b[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){ans+=a[i];}
    cout << ans << endl;
    return 0;
}