#include<bits/stdc++.h>
using namespace std; 

int main(){ 
    string s;
    cin >> s;
    int n = s.length();
    int a = 0,b=0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'A')
        {
            a += b;
        }
        else if(s[i] == 'Q')
        {
            ans += a;
            b++;
        }
    }
    // cout << a << " " << b << endl;
    cout << ans << endl; 
    return 0;
}