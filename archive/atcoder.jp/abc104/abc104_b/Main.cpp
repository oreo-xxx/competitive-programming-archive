#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	string s; cin >>s;
	int n = s.size();
    if(s[0]!='A'){
        cout << "WA" << endl;
	    return 0;
    }
    bool used = false;
	for(int i = 1; i < n; ++i){
        if(i!=1 && i!= n-1 && s[i]=='C'){
          if(used){
            cout << "WA" << endl;
	        return 0;
          }
          used = true;
          continue;
        }
		char base = 'a';
		int tmp = (int)(s[i]- base);
		if(0<=tmp && tmp < 26){continue;}
		else{
			cout << "WA" << endl;
			return 0;
        }
    }
   if(used){cout << "AC" << endl;}
    else{cout << "WA" << endl;}
    return 0;
}
