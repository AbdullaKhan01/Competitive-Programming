#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){ 
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        set<int> s;
        vector<int> ans;
        for(int i=0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
        ans.push_back(x);
        } 
        if(s.size()>=3){
            cout << "NO" << endl;
        }
        else if(s.size()==2)
        {
            auto x = s.begin();
            int l = count(ans.begin(),ans.end(),*x);
            x++;
            int m = count(ans.begin(),ans.end(),*x);
            if(abs(l-m)<=1)
            {
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

        }
        else{
            cout << "YES" << endl;
        }
    
    }
    return 0;
}