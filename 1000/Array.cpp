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
#define yes "Yes"
#define no "No"
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
        vector<int> arr(n);
        bool flag = false;
        vector<int> n1,n2;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            // arr[i] %= 100;
            string s = to_string(arr[i]);
            int g = s[s.size()-1] - 48;
            int k;
            if(s.size() == 1) k = 0;
            else k = s[s.size()-2] - 48;
            if(g == 0 || g == 5) flag = true;
            if(g == 5) arr[i] += 5;
            if(g == 1 || g == 2 || g == 4 || g == 8) n1.pb(k);
            else if(g == 3 || g == 6 || g==7 || g == 9) n2.pb(k);
        }
        //handle case of 5 and 0
        // output(arr);
        // cout << endl;
        if(flag == true)
        {
            bool e1 = true;
            for(int i=0;i<n;i++)
            {
                if(arr[i] != arr[0]) e1 = false;
            }
            cout << (e1?yes:no) << endl;
        }
        else
        {
            bool isOdd1 = true,isEven1 = true;
            for(int i=0;i<n1.size();i++)
            {
                if(n1[i] % 2 == 0) isOdd1 = false;
                else isEven1 = false;
            }
            bool isOdd2 = true, isEven2 = true;
            for(int i=0;i<n2.size();i++)
            {
                if(n2[i] % 2 == 0) isOdd2 = false;
                else isEven2 = false;
            }

            if((isOdd1 || isEven1) && (isOdd2 || isEven2))
            {
                if(n1.size() == 0 || n2.size() == 0) 
                {
                    cout << yes << endl;
                }
                else
                {
                    if(n1[0]%2 != n2[0]%2)
                    {
                        cout << yes << endl;
                    }
                    else
                    {   
                        cout << no << endl;
                    }
                }
            }
            else
            {
                cout << no << endl;

            }
        }
    }
    return 0;
}