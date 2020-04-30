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
    unsigned long long n; cin >> n;
    unsigned long long a; cin >> a;
    unsigned long long b; cin >> b;
    unsigned long long c; cin >> c;
    unsigned long long d; cin >> d;
    unsigned long long e; cin >> e;

    vector<unsigned long long> paths {a, b, c, d, e};

    unsigned long long min = 0xffffffffffffffff;
    for(int i = 0; i < 5; ++i){
        if(min > paths[i]){
            min = paths[i];
        }
    }
    unsigned long long answer = 0;
    unsigned long long tmp = (unsigned long long) ceil((double) n / (double)min);
    answer = 4 + tmp;  
    cout << answer << endl;
    return 0;
}
