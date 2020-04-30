#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    string S; cin >> S;
    string seeds[] = {"dream", "dreamer", "erase", "eraser"};
    reverse( S.begin(), S.end() );
    for(int i = 0; i < 4; ++i ) reverse(seeds[i].begin(), seeds[i].end());
    string T = "";
    bool ans = true;
    for(int i = 0; i < S.size();){
        bool endflag = true;
        for(int j = 0; j < 4; ++j){
            if(S.substr(i, seeds[j].size()) == seeds[j]){
                endflag = false;
                i += seeds[j].size();
            }
        }
        if(endflag) {
            ans = false;
            break;
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

