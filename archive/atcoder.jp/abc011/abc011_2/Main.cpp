#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
 
char aA(char c){
int tmp = c-'A';
if(0<=tmp&& tmp<26)return c;
return c-'a'+'A';
}

char Aa(char c){
int tmp = c-'a';
if(0<=tmp&& tmp<26)return c;
return c-'A'+'a';
}

int main(){
string s;cin >> s;
int n = s.size();
cout << aA(s[0]);
for(int i = 1; i < n; ++i){
cout << Aa(s[i]);
}
cout << endl;
}
