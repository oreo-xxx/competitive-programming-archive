#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int b;
    cin >> b;
    int c;
    cin >> c;

    if( (a < c && c < b)
        ||(b < c && c < a)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
    return 0;
}
