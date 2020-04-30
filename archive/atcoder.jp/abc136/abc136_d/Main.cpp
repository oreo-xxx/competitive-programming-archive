#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    const string yes = "Yes";
    const string no = "No";

    string s; cin >> s;
    int n = s.size();

    vector<int> tmpr(n+1);
    for(int i = 0; i < n; ++i){
        if(s[i] == 'R'){
            tmpr[i + 1] = tmpr[i] + 1;
        }
    }
    vector<int> sumr(n);
    for(int i = 0; i < n; ++i){
        if(tmpr[i] > 0 && tmpr[i + 1] == 0){
            sumr[i] = tmpr[i];
        }
    }

    vector<int> tmpl(n+1);
    for(int i = n - 1; i >= 0; --i){
        if(s[i] == 'L'){
            tmpl[i] = tmpl[i + 1] + 1;
        }
    }
    vector<int> suml(n);
    for(int i = n - 1; i >= 0; --i){
        if(tmpl[i] > 0 && tmpl[i - 1] == 0){
            suml[i-1] = tmpl[i];
        }
    }


    for(int i = 0; i < n; ++i){
        int tmp = sumr[i] / 2 + sumr[i] % 2;
        sumr[i] -= tmp;
        sumr[i-1] += tmp;
    }

    for(int i = n-1; i >= 0; --i){
            int tmp = suml[i] / 2 + suml[i] % 2;
            suml[i] -= tmp;
            suml[i+1] += tmp;
    }

    vector<int> ans(n);
    for(int i = 0; i < n; ++i){
        ans[i] = sumr[i] + suml[i];
    }
    
    for(int i = 0; i < n-1; ++i){
        cout << ans[i] << " ";
    }
    cout << ans[n - 1] << endl;

    return 0;
}
