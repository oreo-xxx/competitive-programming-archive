#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    string s; cin >>s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(i%2==0 && s[i] == 'p'){
            --ans;
        }
        else if(i%2==1&&s[i]=='g'){
            ++ans;
        }
    }
     cout << ans << endl;
    return 0;
}