#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
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
signed main(){
	
    ll tt;
    cin >> tt;
    while(tt--)
    {
        int n,m;
        cin >> n >> m;
        vi arr(n),brr(m);
        input(arr);
        input(brr);
        sort(all(arr));
        sort(all(brr));
        int ii = 0, jj = m-1;
        int sum = 0;
        int i = 0,j=n-1;
        while(i<=j){
            int p = arr[i];
            int q = arr[j];
            int a = brr[ii];
            int b = brr[jj];
            if(max(abs(p-a),abs(p-b))>max(abs(q-a),abs(q-b))){
                if(abs(p-a)>=abs(p-b)){
                    sum+=abs(p-a);
                    ii++;
                }
                else{
                    sum+=abs(p-b);
                    jj--;
                }
                i++;
            }
            else{
                j--;
                if(abs(q-a)>=abs(q-b)){
                    sum += abs(q-a);
                    ii++;
                }
                else{
                    sum += abs(q-b);
                    jj--;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}