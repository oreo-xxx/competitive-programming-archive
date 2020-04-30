#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; string s;
    cin >> n >> s;
	
    int ans = 0;
    for(int i = 0; i < n; ++i){
                int j =0;
		for(j = i+1; j < n; ++j){
			if(s[i] != s[j]){break;}
        }
        i = j-1;
        ++ans ;
    }
    
    cout << ans << endl;
    return 0;
}