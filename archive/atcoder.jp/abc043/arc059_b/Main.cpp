#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    string s; cin >>s;
    int n = s.size();
    
    if(s[0]==s[1]){
        cout << "1 2" << endl;
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        if(s[i]==s[i-1]){
            cout << i << " " << i+1 << endl;
            return 0;
        }
        if(s[i]==s[i-2]){
            cout << i-1 << " " << i+1 << endl;
            return 0;
        }
    }
    
    cout << "-1 -1" << endl;
    return 0;
}