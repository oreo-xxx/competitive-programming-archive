#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

void solve(){
    string s; cin >> s;
    int n = s.size();
    map<char, int> mp;
    for(int i = 0; i < n; ++i){
        ++mp[s[i]];
    }
    if(mp.size() == 1){
        cout << "0\n";
        return;
    }

    ll ans = INF64;

    for(auto it : mp){
        string str = s;
        string str2;
        ll tmp = 0;
        bool flag = true;
        while(flag){
            ++tmp;
            str2.clear();
            for(int i = 0; i < str.size() - 1; ++i){
                if(str[i] == it.first || str[i + 1] == it.first ){
                    str2 += it.first;
                }
                else{
                    str2 += str[i];
                }
            }

            flag = false;
            for(int i = 0; i < str2.size() ; ++i){
                if(str2[i] != it.first){
                    str = str2;
                    flag = true;
                    break;
                }
            }
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';

    return;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

