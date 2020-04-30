#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <climits>
#include <queue>

using namespace std;


int main() {
    string s; cin >> s;
    int k; cin >> k;

    int count = 0;
    int i = 0;
    for(i = 0; i < s.size(); ++i){
        if(s[i] == '1'){
            ++count;
        }
        else{
            cout << s[i] << "\n";
            return 0;
        }

        if(count == k){
            cout << 1 << "\n";
            return 0;
        }
    }
    return 0;
}