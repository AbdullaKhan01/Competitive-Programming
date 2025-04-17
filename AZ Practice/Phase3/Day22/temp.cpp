#include<bits/stdc++.h>
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
int n,t;
void solve()
{

    auto ask = [&](int q)
    {
        cout << "? " << 1 << " " << q << endl;
        int l;
        cin >> l;
        return l;
    };
    cin >> n >> t;
    // 2
    // 1 0 1 1 0 0 0 0 1  0  1
    // 1 2 3 4 5 6 7 8 9 10 11
    while(t--)
    {
        int k;cin >> k;
        int s = 1 , e = n;
        while(s <= e)
        {
            int mid = (s+e)/2;
            int x = ask(mid);
            int ones = x;
            int zeroes = mid - ones;
            if(zeroes < k)
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            // let's say the value of ask is x
        }
        cout << "! " << s << endl;
    }
}
signed main(){
	fast_io();
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
    	solve();
    }
    return 0;
}