#include<bits/stdc++.h>
#define int long long
using namespace std; 

signed main(){

    int tt;
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(auto &a:arr) cin >> a;
        vector<pair<int,int>> vp;
        int g = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] != 0)
            {
                vp.push_back({arr[i],i+1});
                g++;
            }
        }
        
        if(g == 0)
        {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            continue;
        }
        
        if((g % 2) != 0)
        {
            cout << -1 << endl;
            continue;
        }

        vector<pair<int,int>> ans;
        int gz = 0;
        for(int i=1;i<(int)vp.size();i+=2)
        {
            pair<int,int> p1 = vp[i-1];
            pair<int,int> p2=vp[i];
            int a = p1.first;
            int b=p2.first;
            int l = p1.second;
            int r=p2.second;
            if(a != b)
            {
                ans.push_back({l,r-1});
                ans.push_back({r,r});
                gz+=2;
            }
            else
            {

                if((r-l) % 2 != 0)
                {
                    // size is even
                    ans.push_back({l,r});
                    gz+=1;
                }
                else
                {
                    //size is odd
                    ans.push_back({l,l});
                    ans.push_back({l+1,r});
                    gz+=2;
                }
            }
        } 
        
        int s = 1;
        for(auto it:ans)
        {
            int l = it.first;
            int r = it.second;
            if(l != s)
            {
                ans.push_back({s,l-1});
                gz++;
            }
            s = r+1;
        }
        if(s <= n)
        {
            ans.push_back({s,n});
            gz++;
        }
        sort(ans.begin(),ans.end());

        cout << gz << endl;
        for(int i=0;i<gz;i++)
        {
            pair<int,int> it = ans[i];
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}