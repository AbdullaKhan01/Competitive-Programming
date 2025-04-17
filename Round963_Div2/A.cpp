#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	ll tt;
	cin >> tt;
	while(tt--)
	{
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int ch[4]={0};
	    for(int i=0;i<(int)s.size();i++)
	    {
	    	if(s[i] == '?') continue;
	    	ch[s[i]-'A']++;
	    }
	    int ans = 0;
	    for(int i=0;i<4;i++)
	    {
	    	ans += min(n,ch[i]);
	    }
	    cout << ans << endl;
	}
    
    return 0;
}