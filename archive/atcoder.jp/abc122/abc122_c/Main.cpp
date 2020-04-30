#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include <cmath>
#include<climits>
using namespace std;

int main()
{
    long long n; cin >> n;
    long long q; cin >> q;
    string s; cin >> s;
    vector<long long> ls(q);
    vector<long long> rs(q);
    for(int i = 0; i < q; ++i){
        cin >> ls[i];
        cin >> rs[i];
    }

    vector<long long> ac_num(n);
    for(int i = 0; i < n - 1; ++i){
        if( (s[i] == 'A') && (s[i + 1] == 'C') ){
            ac_num[i + 1] = ac_num[i] + 1;
        }
        else{
            ac_num[i + 1] = ac_num[i];
        }
    }

    for(int i = 0; i < q; ++i){
        long long answer = ac_num[ rs[i] - 1 ] - ac_num[ ls[i] - 1 ];
        cout << answer << endl;
    }  
    return 0;
}
