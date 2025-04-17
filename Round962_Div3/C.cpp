#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define floor(a,b)((a-b+1)/b)
#define fast_io() ios::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define int long long
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define output(x) for(auto a:x) cout << a <<" ";
#define rep(i,a,n) for(int i=(a);i<n;i++)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define yes "YES"
#define no "NO"
#define endl '\n'
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,q;
        cin >> n >> q;
        string a,b;
        cin >> a >> b;
        vector<vector<int>> pref1(n+1,vector<int>(26,0));
        vector<vector<int>> pref2(n+1,vector<int>(26,0));

        for(int i=0;i<n;i++)
        {
        	pref1[i+1] = pref1[i];
        	pref1[i+1][a[i]-'a']++;

        	pref2[i+1] = pref2[i];
        	pref2[i+1][b[i]-'a']++;
        }
        while(q--)
        {
        	vector<int> p(26,0);
        	int l,r;
        	cin >> l >> r;
        	int cnt = 0;
        	for(int i=0;i<26;i++)
        	{
        		p[i] = pref1[r][i] - pref1[l-1][i];
        		int z = pref2[r][i] - pref2[l-1][i];
        		if(z >= p[i]) continue;
        		else cnt += p[i] - z;
        	}
        	cout << cnt << endl;	
        }
    }
    return 0;
}
/*
5 3
abcde

alsdjkfasldkjfalskdjfasndsadfnaskd
[a:1,d:1,j:1,k:1,l:1,s:1]
012345678

edcba -> 

// 12345678 1|2|3456|7|8
// 34566891 13456689



1 5 -> 0
1 4 
3 3
*/