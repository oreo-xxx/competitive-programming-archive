#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    std::string s; cin >> s;
    std::string t; cin >> t;
    map<char, char> mp {};
    map<char, char> mp2 {};

    bool flag = true;
    for(int i = 0; i < s.size(); ++i){
        auto itr = mp.find(s[i]);
        if( itr == mp.end() ) {
            mp[s[i]] = t[i];
        } else {
            if (mp[s[i]] != t[i]) {
                flag = false;
                break;
            }
        }
        auto itr2 = mp2.find(t[i]);
        if( itr2 == mp2.end() ) {
            mp2[t[i]] = s[i];
        } else {
            if (mp2[t[i]] != s[i]) {
                flag = false;
                break;
            }
        }

    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    return 0;
}