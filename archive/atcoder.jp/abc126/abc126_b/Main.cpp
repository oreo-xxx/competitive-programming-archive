#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool check_month(int num){
  if (1 <= num && num <= 12 ) return true;
  else return false;
}


int main()
{
    string s; cin >> s;
    int left = stoi( s.substr (0,2) );
    int right = stoi( s.substr (2,2) );

    bool left_month = check_month(left);
    bool right_month = check_month(right);

    if( left_month && right_month ){
      cout << "AMBIGUOUS" << endl;
    }
    else if( left_month && right_month == false ){
      cout << "MMYY" << endl;
    }
    else if( left_month == false && right_month ){
      cout << "YYMM" << endl;
    }
    else{
      cout << "NA" << endl;
    }
    return 0;
}
