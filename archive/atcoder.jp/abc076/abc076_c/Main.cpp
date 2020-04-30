#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool comp(P a, P b){return a.second < b.second;}

void findAllOccurances(vector<size_t>& vec, string& data, string toSearch)
{
    size_t pos = data.find(toSearch);
    while( pos != string::npos)
    {
        vec.push_back(pos);
        pos = data.find(toSearch, pos + toSearch.size());
    }
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s, t; cin >> s >> t;
    int len = s.size();
    int last_index = 0;
    bool ret = false;
    for(int i = 0; i < s.size() - t.size() + 1; ++i){
        bool flag = true;
        for(int j = 0; j < t.size(); ++j){
            if(s[i + j] != '?' && s[i + j] != t[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            ret = true;
            last_index = i;
        }
    }

    if(!ret){
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for(int j = 0; j < t.size(); ++j){
        s[last_index + j] = t[j];
    }
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '?'){
            s[i] = 'a';
        }
    }
    cout << s << endl;

    return 0;
}

