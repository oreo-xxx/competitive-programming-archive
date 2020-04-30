#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < 4; ++i){
        mp[s[i]]++;
    }

    int size = 0;
    bool flag = true;
    for(auto itr : mp){
        ++size;
        if(itr.second != 2){
            flag = false;
        }

    }
    if(size != 2){
        flag = false;
    }

    if(flag){
        cout << "Yes" << endl;
    }
    else{
         cout << "No" << endl;
    }

    return 0;
}
