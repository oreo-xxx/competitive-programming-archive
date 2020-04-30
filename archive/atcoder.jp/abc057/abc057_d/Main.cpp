#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll ans = 1;
    for(int i = 1; i <= k; ++i){
         ans *= (n+1)-i;
         ans /= i;
    }
    return ans;
}

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<ld> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ld>());
    ld sum =0;
    for(int i = 0; i < a; ++i){
    	sum+=v[i];
    }
    cout << fixed << setprecision(10) <<  sum/(ld)a << endl;
    ld last = v[a-1];
    int rem=0, c =0;
    for(int i = 0; i < n; ++i){
    	if(last==v[i]){
    	    ++c;
            if(c==1){rem=i;}
        }
    }
  
    ll ans = 0;
    if(rem!=0){
    	ans=COM(c, a-rem);
    }
    else{
    	for(int i = a; i <= b; ++i){
    	    ans+=COM(c, i);
        }
    }
    cout << ans << endl;
}