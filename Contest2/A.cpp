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
        vi arr(n),brr;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        for(int i=1;i<n;i++)
        {
            brr.push_back(__gcd(arr[i],arr[i-1]));
        }
        vector<pair<int,bool>>a1(n),a2(n);
        a1[0] = {brr[0],1};
        for(int i=1;i<n;i++)
        {
            a1[i] = {brr[i-1],a1[i-1].second && 
                    brr[i-1]>=a1[i-1].first};
        }
        a2[n-1] = {brr[n-2],1};
        for(int i=n-2;i>=0;i--)
        {
            a2[i] = {brr[i],a2[i+1].second && 
                    brr[i]<=a2[i+1].first};
        }
        int cnt = 0;
        for(auto it:a1)
        {
            cout << it.ff << " " << it.ss << endl;
        }
        cout << endl;
        for(auto it:a2)
        {
            cout << it.ff << " " << it.ss << endl;
        }
        cout << endl;

        for(int i=0;i<n;i++)
        {
            bool left = true , right = true;
            int lv = INT_MIN , rv = INT_MAX;
            if(i-2>=0)
            {
                left = a1[i-2].second;
                lv = a1[i-2].first;
            }
            if(i+1 < n)
            {
                right = a2[i+1].second;
                rv = a2[i+1].first;
            }
            cout << i << " " << lv << " " << rv << " " << left << " " << right << endl;
            if(i == 0)
            {
                if(right)
                {
                    cout << "here " << i << endl;
                    cnt++;
                }

            }
            else if(i == n-1)
            {
                if(left)
                {
                    cout << "here " << i << endl;
                    cnt++;
                }
            }
            else 
            {
                int sm = __gcd(arr[i-1],arr[i+1]);
                cout << sm << endl;
                if(left && right)
                {
                    // cout << "aaye" << endl;
                    if(lv <= sm && sm <= rv)
                    {
                        cout << "here " << i << endl;
                        cnt++;
                    }

                }
            }
        }
        if(cnt == 1)
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}