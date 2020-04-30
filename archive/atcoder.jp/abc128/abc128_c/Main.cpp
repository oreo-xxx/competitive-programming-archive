#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <climits>

using namespace std;

int main() {
    const long long INF = 1LL << 60;

    int n; cin >> n;
    int m; cin >> m;
    vector< vector<int> > vec(m);
    for(int i =0; i < m; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int s; cin >> s;
            vec[i].push_back(s);
        }
    }

    vector<int> p(m);
    for(int i =0; i < m; ++i){
        cin >> p[i];
    }

    int count = 0;
    for(int bit =0; bit < (1L << n); ++bit){
        bool flag = true;
        for(int i = 0; i < m; ++i){
            int flagcount = 0;
            for(int j = 0; j < vec[i].size(); ++j){
                if(bit & (1 << (vec[i][j] - 1) ) ){
                    flagcount++;
                }
            }
            if(flagcount % 2 != p[i])
            {
                flag = false;
            }
        }
        if(flag){
            ++count;
        }
    }
    cout << count << endl;


    return 0;
}