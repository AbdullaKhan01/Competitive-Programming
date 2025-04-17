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
    string a,b;
    cin >> a >> b;
    string ans;
    for(int i=0;i<a.size();i++){
        int l = a[i]-48;
        int m = b[i]-48;
        ans.push_back((l^m)+48);
    }
    cout << ans << endl;
    return 0;
}