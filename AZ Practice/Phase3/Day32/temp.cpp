#include<bits/stdc++.h>
using namespace std; 
/* 
for fast input output use printf and scanf;
*/
void print(stack<int> st)
{
	if(st.empty())
	{
		cout << "Stack is empty" << endl;
		return ;
	}
	cout << "Stack elements: ";
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}
bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return x >= 2;
}
void push(stack<int>&st,int x)
{
	cout << "Pushing primes up to "<<x<<": ";
	for(int i=2;i<=x;i++)
	{
		if(isPrime(i))
		{
			st.push(i);
			cout << i << " ";
		}
	}
	cout << endl;
}
int main(){
	int n;
	cin >> n;
	stack<int> st;
	while(n != 5)
	{
		if(n == 1)
		{
			int a;cin >> a;
			st.push(a);
		}
		else if(n == 2)
		{
			if(st.empty())
			{
				cout << "Stack is empty" << endl;
			}
			else st.pop();
		}
		else if(n == 3)
		{
			print(st);
		}
		else if(n == 4)
		{
			if(st.empty())
			{
				cout << "Stack is empty" << endl;
			}
			else push(st,st.top());
		}
		else
		{
			cout << "Invalid choice" << endl;
		}
		cin >> n;
	}	
    return 0;
}