#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tt;
    cin >> tt;
    while(tt--){
    	int ll;
    	cin >> ll;
        string s;
        cin >> s;
        string ans;
        bool flag = false;
        int cnt = 1;
        for(int i=0;i<(int)s.size();i++){
        	if(i+1<ll){
        		if(s[i]>s[i+1] && cnt>0){
        			// swap(s[i],s[i+1]);
        			ans.push_back(s[i+1]);
        			flag = true;
        			cnt--;
        			i++;
        		}
        		else{
        			ans.push_back(s[i]);
        		}
        	}
        	else{
        		ans.push_back(s[ll-1]);
        	}
        }
        if(flag == false) ans.pop_back();
        cout << ans << endl;
    }
}
