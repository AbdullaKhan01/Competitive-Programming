#include<bits/stdc++.h>
#include<algorithm>
using namespace std; 
#define ll long long


// VERDICT -> ACCEPTED
bool isPossible(int a,int b,int c,int x,int y,int z,int pb,int ps,int pc,int money,int count){
    long long bun = ((count*a) - x) * pb;
    long long sauce = ((count*b) - y) * ps;
    long long chee = ((count*c) - z) * pc;
    long long sum=0;
    if(bun > 0) sum+=bun;
    if(sauce > 0) sum+=sauce;
    if(chee > 0) sum+=chee;
    if(sum >= money){
        return true;
    }
    return false;
    // long long bun = (count - x) * pb;
    // long long sauce = (count - y) * ps;
    // long long chee = (count - z) * pc;
    
}
int main(){ 
    string s;
    cin >> s;
    long long a=0,b=0,c=0;
    long long x,y,z,pb,ps,pc;
    cin >> x >> y >> z;
    cin >> pb >> ps >> pc;
    long long money;
    cin >> money;
    for(int i=0;i<(int)s.length();i++){
        a+=(s[i]=='B');
        b+=(s[i]=='S');
        c+=(s[i]=='C');
    }
    long long price = (a*pb) + (b*ps) + (c*pc);
    long long range = max(x,y,z) + (money/price);
    long long st = 0,e = range;
    long long ans=0;
    long long mid = st + (e-st)/2;
    while(st<=e){
        if(isPossible(a,b,c,x,y,z,pb,ps,pc,money,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = st + (e-st) / 2;
    }
    cout << ans << endl;
    return 0;
}