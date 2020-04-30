#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    return a / g * b;
}

int main(){
    int n; string s1, s2;
    cin >> n >>s1 >> s2;
	ll ans = 1;
	int i = 0; bool flag = false;
	if(s1[i] == s2[i]){
			ans *= 3;
			flag = true;
        }
        else{
        	i++;
            ans *= 6;
        }
        ++i;
        
	for(; i < n; ++i){
		if(s1[i] == s2[i]){
			if(flag){ans *=2;}
			else{ans *= 1;}
			flag =true;
        }
        else{
        	i++;
            if(flag ){ans*=2;}
            else{ans *= 3;}
            flag =false;
        }
      ans %= MOD;
    }
    cout << ans << endl;
}