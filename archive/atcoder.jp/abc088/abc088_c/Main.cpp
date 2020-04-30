#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    vector<vector<int> > c(3);
    for(int i = 0; i < 3; ++i){
    	for(int j = 0; j < 3; ++j){
    	    int tmp; cin >> tmp;
    	    c[i].push_back(tmp);
        }
    }
    for(int a1 = -100; a1 <= 100; ++a1){
    	int b1 = c[0][0]-a1;
        int b2 = c[0][1]-a1;
        int b3 = c[0][2]-a1;
        
        int a2 = c[1][0]-b1;
        if(a2 != c[1][1] - b2 || a2 != c[1][2] - b3){continue;}
        
        int a3 = c[2][0]-b1;
        if(a3 != c[2][1] - b2 || a3 != c[2][2] - b3){continue;}
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}