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
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<char>>arr(n,vector<char>(m,' '));
        rep(i,0,n){
        	rep(j,0,m){
        		cin >> arr[i][j];
        	}
        }
        k++;
        vector<vector<int>>rowR(n+1,vector<int>(m+1,0));
        vector<vector<int>>rowL(n+1,vector<int>(m+1,0));
        vector<vector<int>>colD(n+1,vector<int>(m+1,0));
        vector<vector<int>>colU(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
        	int j;
        	for(j=m-1;j>m-k-1 && j>=0;j--){
        		if(j+1<=m)
        		rowR[i][j] = rowR[i][j+1] + (arr[i][j]=='#');
        	}
        	for(;j>=0;j--){
        		if(j+k<=m)
        		rowR[i][j] = rowR[i][j+1] + (arr[i][j]=='#') - (arr[i][j+k]=='#') ;
        	}
        }
        for(int i=0;i<n;i++){
            int j;
            rowL[i][0] = (arr[i][0] == '#');
            for(j=1;j<k && j<m;j++){
                if(j-1>=0)                                                     
                rowL[i][j] = rowL[i][j-1] + (arr[i][j]=='#');
            }
            for(;j<m;j++){
                rowL[i][j] = rowL[i][j-1] + (arr[i][j]=='#') - (arr[i][j-k]=='#') ;
            }
        }

        for(int i=0;i<m;i++){
            int j;
            for(j=n-1;j>n-k-1 && j>=0;j--){
                if(j+1<=n)
                colD[j][i] = colD[j+1][i] + (arr[j][i]=='#');
            }
            for(;j>=0;j--){
                colD[j][i] = colD[j+1][i] + (arr[j][i]=='#');
                if(j+k<=n) colD[j][i] -= (arr[j+k][i]=='#');
            }
        }

        for(int i=0;i<m;i++){
            int j;
            colU[0][i] = (arr[0][i] == '#');
            for(j=1;j<k && j<n;j++){
                if(j-1>=0)
                colU[j][i] = colU[j-1][i] + (arr[j][i]=='#');
            }
            for(;j<n;j++){
                if(j-k>=0)
                colU[j][i] = colU[j-1][i] + (arr[j][i]=='#') - (arr[j-k][i]=='#') ;
            }
        }

        // int maxi = INT_MIN;
        // rep(i,0,n){
        //     rep(j,0,m){
        //         if(arr[i][j]=='#')
        //         maxi = max(maxi,(max(rowL[i][j],rowR[i][j])+max(colD[i][j],colU[i][j])) - 1);
        //     }
        // }
        // cout << maxi << endl;
        rep(i,0,n){
            rep(j,0,m){
                cout << rowL[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        rep(i,0,n){
            rep(j,0,m){
                cout << rowR[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        rep(i,0,n){
            rep(j,0,m){
                cout << colU[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        rep(i,0,n){
            rep(j,0,m){
                cout << colD[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}
/*

        

        

        

        rep(i,0,n){
            rep(j,0,m){
                cout << rowL[i][j] << " ";
            }
            cout << endl;
        }

        rep(i,0,n){
            rep(j,0,m){
                cout << rowR[i][j] << " ";
            }
            cout << endl;
        }

        rep(i,0,n){
            rep(j,0,m){
                cout << colU[i][j] << " ";
            }
            cout << endl;
        }
        rep(i,0,n){
            rep(j,0,m){
                cout << colD[i][j] << " ";
            }
            cout << endl;
        }
        
*/