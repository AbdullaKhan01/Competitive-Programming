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
int apSum(int st,int n)
{
	int d = -1;
	int sum = (n*((2*st) + (n-1)*d))/2;
	return sum;
}
signed main(){
	fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vi arr(n+1);
        for(int i=1;i<=n;i++)
        {
        	cin >> arr[i];
        }
        vi pref(n+1,0);
        for(int i=1;i<=n;i++)
        {
        	pref[i] = pref[i-1] + arr[i];
        	// cout << pref[i] << " ";
        }
        // cout << endl;
        int q;
        cin >> q;

        while(q--)
        {
        	int l,sum;
        	cin >> l >> sum;
			int s=l,e=n;
			// just do binary search on the prefix sum array
			int fact = pref[s-1];
			int ans = n;
			// cout << "starting " << fact << endl;
			while(s <= e)
			{

				int mid = (s+e)/2;
				// cout << mid << " " << pref[mid]-fact << endl;
				if(pref[mid]-fact >= sum)
				{
					ans = mid;
					e = mid-1;
				}
				else
				{
					s = mid+1;
				}
			}
			// 1 5 6 9 11 20
			if(ans == l)
			{
				cout << ans << " ";
				continue;
			}
			// now choose the best answer
			int c1 = ans;
			int c2 = ans-1;
			if(apSum(sum,pref[c1]-fact) > apSum(sum,pref[c2]-fact))
			{
				cout << c1 << " ";
			}
			else cout << c2 << " ";

        }
        cout << '\n';
    }
    return 0;
}