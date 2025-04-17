// // #include<bits/stdc++.h>
// // #define mod 1000000007
// // #define mod2 998244353
// // #define ceil(a,b) ((a+b-1)/b)
// // #define floor(a,b)((a-b+1)/b)
// // #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// // #define ll long long
// // #define int long long
// // #define vi vector<int>
// // #define all(x) (x).begin(),(x).end()
// // #define rall(x) (x).rbegin(),(x).rend()
// // #define input(x) for(auto &a:x) cin >> a;
// // #define output(x) for(auto a:x) cout << a <<" ";
// // #define rep(i,a,n) for(int i=(a);i<n;i++)
// // #define pb push_back
// // #define ppb pop_back
// // #define pf push_front
// // #define ppf pop_front
// // #define ff first
// // #define ss second
// // #define si set<int>
// // #define pii pair<int,int>
// // #define mii map<int,int>
// // #define msi map<string,int>
// // #define yes "YES"
// // #define no "NO"
// // #define endl '\n'
// // using namespace std; 
// // /* 
// // for fast input output use printf and scanf;
// // */
// // signed main(){
// //     fast_io();
// //     ll tt;
// //     cin >> tt;
// //     while(tt--)
// //     {
// //         int n,m;
// //         cin >> n >> m;
// //         vector<int> prog(n+m+1),test(n+m+1);
// //         input(prog);
// //         input(test);
// //         vector<char> dev(n+m+1);
// //         vector<int> p,t;
// //         int cnt=0,cnt2=0;
// //         int sp = 0 , st = 0;
// //         int lp = -1 , lt = -1;
// //         int firstTesterProgrammer = -1;
// //         int firstProgrammerTester = -1;
// //         for(int i=0;i<n+m;i++)
// //         {

// //             if((cnt2==m)||(prog[i] > test[i] && cnt < n))
// //             {
// //                 if(cnt2 == m)
// //                 {
// //                     if(firstProgrammerTester == -1)
// //                     {
// //                         firstProgrammerTester = i;
// //                     }
// //                     dev[i] = 'P';
// //                     cnt++;
// //                     sp += prog[i];
// //                 }
// //                 else{
// //                     dev[i] = 'P';
// //                     cnt++;
// //                     sp += prog[i];
// //                     lp = i;
// //                 }
// //             }
// //             else
// //             {
// //                 if(cnt == n)
// //                 {
// //                     if(firstTesterProgrammer == -1)
// //                     {
// //                         firstTesterProgrammer = i;
// //                     }
// //                     dev[i] = 'T';
// //                     cnt2++;
// //                     st += test[i];
// //                 }
// //                 else{
// //                     dev[i] = 'T';
// //                     cnt2++;
// //                     st += test[i];
// //                     lt = i;
// //                 }
// //             }
// //         }
// //         cout << sp << " " << st << " "  << firstProgrammerTester << " " << firstTesterProgrammer << endl;
// //         output(dev);
        

// //         cout << endl;
// //         for(int i=0;i<n+m;i++)
// //         {
// //             if(dev[i] == 'P')
// //             {
// //                 if(firstTesterProgrammer == -1)
// //                 {
// //                     //last person becomes programmer
// //                     int ans = sp + st - prog[i] + prog[n+m];
// //                     cout << ans << " ";
// //                 }
// //                 else
// //                 {
// //                     //last person becomes tester
// //                     int idx = firstTesterProgrammer;
// //                     int ans = sp + st - test[idx] + prog[idx] + test[n+m];
// //                     cout << ans << " ";
// //                 }
// //             }
// //             if(dev[i] == 'T')
// //             {
// //                 if(firstProgrammerTester == -1)
// //                 {
// //                     //last person becomes tester
// //                     int ans = sp + st - test[i] + test[n+m];
// //                     cout << ans << " ";
// //                 }
// //                 else
// //                 {
// //                     //last person becomes programmer
// //                     int idx = firstProgrammerTester;
// //                     int ans = sp + st - prog[idx] + test[idx] + prog[n+m];
// //                     cout << ans << " ";
// //                 }
// //             }
// //         }
// //         cout << sp + st << " ";
// //         cout << endl;
// //     }
// //     return 0;
// // }

// // #include<bits/stdc++.h>
// // #define mod 1000000007
// // #define mod2 998244353
// // #define ceil(a,b) ((a+b-1)/b)
// // #define floor(a,b)((a-b+1)/b)
// // #define fast_io() ios::sync_with_stdio(0);cin.tie(0);
// // #define ll long long
// // #define int long long
// // #define vi vector<int>
// // #define all(x) (x).begin(),(x).end()
// // #define rall(x) (x).rbegin(),(x).rend()
// // #define input(x) for(auto &a:x) cin >> a;
// // #define output(x) for(auto a:x) cout << a <<" ";
// // #define rep(i,a,n) for(int i=(a);i<n;i++)
// // #define pb push_back
// // #define ppb pop_back
// // #define pf push_front
// // #define ppf pop_front
// // #define ff first
// // #define ss second
// // #define si set<int>
// // #define pii pair<int,int>
// // #define mii map<int,int>
// // #define msi map<string,int>
// // #define yes "YES"
// // #define no "NO"
// // #define endl '\n'
// // using namespace std; 
// // /* 
// // for fast input output use printf and scanf;
// // */
// // signed main(){
// //     fast_io();
// //     ll tt;
// //     cin >> tt;
// //     while(tt--)
// //     {
// //         int n;
// //         cin >> n;
// //         vector<int> arr(n),brr(n+1);
// //         input(arr);
// //         input(brr);
// //         int g = brr[n];
// //         int ans = 1;
// //         int mini = 1e18;
// //         bool flag = false;
// //         for(int i=0;i<n;i++)
// //         {
// //             int n1 = arr[i];
// //             int n2 = brr[i];
// //             ans += (abs(arr[i]-brr[i]));
// //             if(n1 >= n2)
// //             {
// //                 if(g <= n1 && g>=n2)
// //                 { 
// //                     // cout << g << "here " << n1 << " " << n2 << endl;
// //                     flag = true;
// //                 }
// //                 mini = min(mini,abs(g-n1));
// //                 mini = min(mini,abs(g-n2));
// //             }
// //             else
// //             {
// //                 if(g>=n1 && g <= n2)
// //                 {
// //                     // cout << g << "here2" << n1 << " " << n2 << endl;
// //                     flag = true;
// //                 }
// //                 mini = min(mini,abs(g-n1));
// //                 mini = min(mini,abs(g-n2));
// //             }
// //             mini = min(mini,abs(arr[i]-g));
// //         }
// //         // cout << "mini is -> " << mini << endl;
// //         // cout << "flag is -> " << flag << endl;
// //         if(flag == true)
// //         {
// //             cout << ans << endl;
// //         }
// //         else
// //         {
// //             cout << ans + mini << endl;
// //         }
// //     }
// //     return 0;
// // }
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
string decToBin(int n)
{
    if (n == 0)
        return "0";
     
    // to store the binary equivalent of decimal
    string bin = "";    
    while (n > 0)    
    {
        // to get the last binary digit of the number 'n'
        // and accumulate it at the beginning of 'bin'
        bin = ((n & 1) == 0 ? '0' : '1') + bin;
         
        // right shift 'n' by 1
        n >>= 1;
    }
     
    // required binary number
    return bin;
}
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int a,b;
        cin >> a >> b;
        vector<int> cnt(32,0);
        bool flag = false;
        cout << decToBin(a) << endl;
        for(int i=0;i<32;i++)
        {
            int bit = 1 & (a >> i);
            if(bit) flag = true;
            if(!bit)
            {
                cout << "here " << i << endl;
                int s = 0;
                int k = 1;
                int g = -1;
                for(int j=0;j<=i-1;j++)
                {
                    int nbit = 1 & (a>>j);
                    if(nbit)
                    {
                        s |= 1<<j;
                    }
                    else g = j;
                }
                cout << "here " << i << " " << s << " " << g << endl;
                if(g!=-1)
                {
                    int ld = 1;
                    while(g>=0)
                    {
                        k+=ld;
                        ld*=2;
                        g--;
                    }
                }
                if(!flag) s = INT_MAX;
                if(g == -1) cnt[i] = s;
                else cnt[i] = min(s,g);
            }
        }
        output(cnt);
        cout << endl;
        for(int i=31;i>=0;i--)
        {
            int bit = 1 & (a>>i);
            if(!bit && cnt[i] <= b)
            {
                a = a | (1<<i);
            }
        }
        cout << a << endl;
    }
    return 0;
}
