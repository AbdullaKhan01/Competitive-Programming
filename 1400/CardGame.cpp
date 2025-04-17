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
        int n;
        cin >> n;
        char trump;
        cin >> trump;
        n*=2;
        vector<char> suite = {'C','D','H','S'};
 		map<char,int> mp = {{'C',0},{'D',1},{'H',2},{'S',3}};
 		vector<vector<int>>suites(4);
 		for(int i = 0 ; i < n ; i++)
 		{
 			string s;
 			cin >> s;
 			char suite = s[1];
 			int rank = s[0]-48;
 			suites[mp[suite]].push_back(rank);
 		}
 		for(int i=0;i<4;i++)
 		{
 			sort(rall(suites[i]));
 		}
 		int trank = mp[trump];
 		vector<pair<string,string>> ans;
 		bool flag = true;      
 		for(int i=0;i<4;i++)
 		{
 			if(suite[i] == trump) continue;
 			vector<int> temp = suites[i];
 			while(!temp.empty())
 			{
 				string a1 = to_string(temp.back()) + suite[i];
 				temp.ppb();
 				string a2;
 				if(temp.empty())
 				{
 					if(suites[trank].empty())
 					{
 						flag = false;
 						break;
 					}
 					else
 					{
 						a2 = to_string(suites[trank].back()) + trump;
 						suites[trank].ppb();
 					}
 				}
 				else
 				{
 					a2 = to_string(temp.back()) + suite[i];
 					temp.ppb();
 				}
 				ans.pb({a1,a2});
 			}
 		}
 		while(!suites[trank].empty())
 		{
 			if(suites[trank].size() % 2 != 0)
 			{
 				flag = false;
 				break;
 			}
 			else{
 				string a1 = to_string(suites[trank].back()) + trump;
 				suites[trank].ppb();
 				string a2 = to_string(suites[trank].back()) + trump;
 				suites[trank].ppb();
 				ans.pb({a1,a2});
 			}
 		}
 		if(flag)
 		{
 			for(auto it:ans)
 			{
 				cout << it.first << " " << it.second << endl;
 			}
 		}
 		else
 		{
 			cout << "IMPOSSIBLE" << endl;
 		}
    }
    return 0;
}