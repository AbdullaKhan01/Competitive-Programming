#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
string s;

int dp1[1001][1001];
int rec1(int l,int r){ // O(N^2)
    if((r-l+1)<=1)return 1;
    if(dp1[l][r]!=-1){
        return dp1[l][r];
    }
    int ans = (s[l]==s[r] && rec1(l+1,r-1));
    return dp1[l][r] = ans;
}

int dp2[1001];
int rec2(int i){
    if(i==-1){
        return 0;
    }
    if(dp2[i]!=-1)return dp2[i];
    int ans = INF;
    for(int j=i;j>=0;j--){ // [i..j]
        if(rec1(j,i)){
            ans = min(ans, 1 + rec2(j-1));
        }
    }
    return dp2[i]=ans;
}

int main()
{
    cin>>s;
    n = s.length();
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec2(n-1)<<endl;
}