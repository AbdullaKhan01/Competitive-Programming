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
        int n, k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        vector<int> f1(26,0),f2(26,0);
        for(int i=0;i<n;i++)
        {
            f1[a[i]-'a']++;
            f2[b[i]-'a']++;
        }
        map<int,vector<int>> mp1,mp2;
        for(int i=0;i<26;i++)
        {
            if(f1[i]!=0)
                mp1[f1[i]].push_back(i);
            if(f2[i]!=0)
                mp2[f2[i]].push_back(i);
            // if(f1[i] == 0 && f2[i] == 0) continue;
            // if(f1[i] != 0 && f2[i] != 0)
            // {
            //  if(f1[i] == f2[i]) continue;
            //  if(f1[i] > f2[i])
            //  {
            //      mp1[f1[i]-f2[i]].push_back(i);
            //  }
            //  else
            //  {
            //      mp2[f2[i]-f1[i]].push_back(i);
            //  }
            // }
            // else if(f1[i] == 0)
            // {
            //  mp2[f2[i]].push_back(i);
            // }
            // else{
            //  mp1[f1[i]].push_back(i);
            // }
        }
        bool flag = true;
        for(auto it:mp1){
            cout << it.first << " " << it.second.size()<<endl;
        }
        for(auto it:mp2){
            cout << it.first << " " << it.second.size()<<endl;
        }
        
        for(auto it:mp1)
        {

            int freq = it.first;

            if(mp2.find(freq) == mp2.end()){
                cout << "here2 " << freq << endl;
                flag = false;
                continue;
            }
            if(freq < k || it.second.size() != mp2[freq].size()){

                 cout << "here" <<endl;
                 flag = false;  
                 continue;
            }
            vector<int> temp1 = it.second;
            vector<int> temp2 = mp2[freq];
            sort(all(temp1));
            sort(all(temp2));

            for(int i=0;i<temp1.size();i++)
            {
                if(temp1[i] > temp2[i]){
                     flag = false;  
                }
            }
        }

        cout << (flag?yes:no) << endl;
    }
    return 0;
}