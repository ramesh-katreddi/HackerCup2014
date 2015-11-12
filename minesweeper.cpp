#include<iostream>
using namespace std;
int main()
{
	//freopen("input.in","r",stdin);
	int t;
	cin>>t;
	for(int j=0;j<t;j++) 
	{
		int a,b,c;
		bool possible = false;
		cin>>a>>b>>c;
		if (a==1 || b==1) 
		{
			if (a*b == c && c!=1) {
				cout<<j+1<<" impossible"<<endl;
			}
			else {
				cout<<j+1<<" possible"<<endl;
			}
			continue;
		}
		int max = a>b?a:b;
		int min = a<b?a:b;
		int product = a *b;
		c = a*b -c;
		if( c==1) {
			cout<<j+1<<" possible"<<endl;
			continue;
		}
		for( int i = max ; i > 1 ;i--)
		{
			if ( c/i > 1 && c/i < min && c%i != 1 || (c/i>1 && c/i == min && c%i ==0)) {
				possible = true;
				break;
			}
		}
		if (possible)
		{
			cout<<j+1<<" possible"<<endl;
		} else {
			cout<<j+1<<" impossible"<<endl;
		}
	}
	return 0;
}