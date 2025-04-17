// D(K*N) = K * D(N)

// sum of digits of the number (K*n) == K * (sum of digits of Number N)
// D(K*N) / D(N) == K

// this will only by possible we D(K*N) == K*D(N)

//  let's say k = 5 and N = 15

// let's say l = 1 , r = 3

// so we have to consider all the elements from 10 to 1000

// D -> 10 = 1 
// D -> 11 = 2
// D -> 12 = 3
// D -> 19 = 10
// D -> 20 = 2
// D -> 21 = 3

// from 10 to 20 we have 1 to 10
// from 20 to 30 we have 2 to 11
// from 30 to 40 we have 3 to 12
//......
//......
//......
// from 90 to 99 have have 9 to 18

// from 100 to 109 we have 1 to 10
// from 110 to 119 we have 2 to 11
// from 120 to 129 we have 3 to 12



// then D(N) = 1+5 -> 6 && D(K*N) = 5*15 = D(75) = 7+5 -> 12
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

// VERDICT -> ACCEPTED
signed main(){
    fast_io();
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> pos;
        for(int i=0;i<64;i++)
        {
          // cout << (n<<i) << endl;
          if(1LL & (n>>i))
          {
            pos.push_back(i);
          }
        }
        vector<int> ans;


        // 10111
        // [0,1,2,4]
        ans.push_back(n);
        for(auto it:pos)
        {
            int num = ans.back();
            //23  
            bitset<64> b(num);
            b.flip(it);
            // num = num & ~(1LL<<it);
            // cout << num << endl;
            for(int i=0;i<it;i++)
            {
              if(n & (1LL<<i))
              {
                  // if(num & (1LL<<i))
                  b[i] = (b[i]^1);
                  // if(b.test(i))
                  // {
                  //    // num = num & ~(1LL<<i);
                  //   b.flip(i);
                  // }
                  // else num = num | (1LL<<i);
              }
            }
            if(num <= n && num>0)
              ans.push_back(num);
        }

        cout << ans.size() << endl;
        reverse(all(ans));
        output(ans);
        cout << endl;
    }
    return 0;
}

//23 // 10111
     //   111
     // 10000
     // 10111

     // 10111
      
// 7 18 21 22 23
// 5 18 21 22 23

// 10010111



// a1 a2 a3 a4 a5

// 10010110
// 10010101

// a1
// a2
// a3
// a4 
// 10010111