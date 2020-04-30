#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main()
{
    int n; cin >> n;
    int k; cin >> k;
    string s; cin >> s;
    int offset = 'a' - 'A';

    s[k - 1] = s[k - 1] + offset; 

    cout << s << endl;
    return 0;
}
