#include<iostream>
#include<string>
using namespace std;
void print(long long int N, int K,int remainder , string inputString)
{
	if(N == 0)
		return;
	
	remainder = N % K;
	N = N/K;
	char i; 
	if(remainder == 0 )  
	{
		//N = N-1;
		i = inputString.at(K-1);
	}
	else
		i = inputString.at(remainder-1);

	print(N,K,remainder,inputString);
	cout<<i;
}
int main()
{
	freopen("labelmaker_example_input.txt","r", stdin);
	freopen ("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=0 ; i<T; i++)
	{
		std:string inputString ;
		unsigned long long int N;
		cin>>inputString;
		cin>>N;
		int K = inputString.size();
		cout<<"Case #"<<i+1<<": ";
		for(int h=1;h<100;h++)
		{
			print(h, K,-1,inputString);
			cout<<endl;
		}
		cout<<"\n";
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}