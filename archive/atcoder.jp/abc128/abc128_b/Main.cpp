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

bool cmp(const pair<int, pair<string, int> > &a, const pair<int, pair<string, int> > &b)
{
    if(a.second.first != b.second.first){
        return a.second.first < b.second.first;
    }
    else {
        return a.second.second > b.second.second;
    }
}

int main() {
    int n; cin >> n;
    vector< pair<int, pair<string, int> > >vec(n);
    for(int i =0; i < n; ++i){
        string s; cin >> s;
        int p; cin >> p;
        vec[i] = make_pair(i+1, make_pair(s, p) );
    }

    sort(vec.begin(), vec.end(), cmp);

    for(int i =0; i < n; ++i){
        cout << vec[i].first << endl;
    }

    return 0;
}