#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

int main()
{
    string s; cin >> s;
    int count_0 = 0;
    int count_1 = 0;
    for(int i = 0; i < s.size(); ++i){
        if( s[i] == '0') ++count_0;
        else if( s[i] == '1') ++count_1;
    }

    int ans = 2 * min(count_0, count_1);
  
    cout << ans << endl;
    return 0;
}
