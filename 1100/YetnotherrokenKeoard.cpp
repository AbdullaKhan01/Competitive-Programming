#include<bits/stdc++.h>
#define mod 1000000007
#define mod2 998244353
#define ceil(a,b) ((a+b-1)/b)
#define ll long long
#define ll long long
#define lli long long int
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define input(x) for(auto &a:x) cin >> a;
#define llmax(a,b) max(1LL*(a),1LL*(b))
#define output(x) for(auto a:x) cout << a <<" ";
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std; 

int main(){
    ll tt;
    cin >> tt;
    while(tt--)
    {
        string ans;
        string s;cin >> s;
        int a=0,b=0;
        for(int i=s.length()-1;i>=0;i--){
        	if(s[i] == 'b'){
        		a++;
        	}
        	else if(s[i] == 'B'){
        		b++;
        	}
        	else{
        		if(s[i]>='a' && s[i]<='z'){
        			if(a>0) a--;
        			else ans.push_back(s[i]); 
        		}
        		else if(s[i]>='A' && s[i]<='Z'){
        			if(b>0) b--;
        			else ans.push_back(s[i]);
        		}
        		else{
        			ans.push_back(s[i]);
        		}
        	}

        }
        reverse(all(ans));
        cout << ans << endl;
    }
    return 0;
}