#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,  ll>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	ll n, m; string s;
    cin >> n >> m >> s;
    reverse(s.begin(), s.end());
    vector<int> ans;
    for (int i = 0; i < n;) {
        bool flag = true;
        for(int j = m; j >= 1; --j){
           if(i+j>=n+1){continue;}
           if(s[i+j]=='0'){
        	  i += j;
              flag = false;
              ans.push_back(j);
              break;
           }
        }
        if(flag){
          cout << -1 << endl;
          return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
}