// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;
int kmp(string s)
{
	vector<int> lps(s.size(), 0);

	for (int i = 1; i <(int) s.size(); i++) {

		int previous_index = lps[i - 1];

		while (previous_index > 0
			&& s[i] != s[previous_index]) {

			previous_index = lps[previous_index - 1];
		}

		lps[i] = previous_index
				+ (s[i] == s[previous_index] ? 1 : 0);
	}

	return lps[lps.size() - 1];
}

int remainingStringLongestPallindrome(string s)
{
	string t = s + "?";

	reverse(s.begin(), s.end());
	t += s;

	return kmp(t);
}
string longestPrefixSuffixPallindrome(string s)
{
	int length = 0;
	int n = s.size();

	for (int i = 0, j = n - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			break;
		}
		length++;
	}

	string ans = s.substr(0, length);


	string remaining = s.substr(length,
								(n - (2 * length)));

	if (remaining.size()) {

		int longest_prefix
			= remainingStringLongestPallindrome(remaining);

		reverse(remaining.begin(), remaining.end());
	
		int longest_suffix
			= remainingStringLongestPallindrome(remaining);

		if (longest_prefix > longest_suffix) {

			reverse(remaining.begin(), remaining.end());

			ans += remaining.substr(0, longest_prefix);
		}


		else {

			ans += remaining.substr(0, longest_suffix);
		}
	}
	ans += s.substr(n - length, length);
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;

	string g = longestPrefixSuffixPallindrome(str);
	int ans = n - g.size();
	cout << ans << endl;
}
// Driver Code
int main()
{
	// string str = "rombobinnimor";
	int tt;
	cin >> tt;
	while(tt--)
	{
		solve();
	}
}
