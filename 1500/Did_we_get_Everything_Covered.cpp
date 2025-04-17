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
        int n,k,m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        bool visited[26] = {0};
        int freq[26] = {0};
        int sum = 0;
        int cnt = 0;
        string ans = "";
        for(int i=0;i<m;i++)
        {
            if(!visited[s[i] - 'a'])
            {
                visited[s[i]-'a'] = 1;
                freq[s[i]-'a']++;
                sum++;
            }
            if(sum == k)
            {
                ans += s[i];
                cnt++;
                sum = 0;
                for(int i=0;i<k;i++) visited[i] = 0;
            }
        }
        if(cnt >= n)
        {
            cout << yes << endl;
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                if(!visited[i])
                {
                    while(ans.size() < n) ans+=(char)(i+'a');
                }
            }
            cout << no << endl;
            cout << ans << endl;
        }
    }
    return 0;
}