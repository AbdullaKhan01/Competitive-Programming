#include<bits/stdc++.h>
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    int n;string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}