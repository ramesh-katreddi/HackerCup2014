#include<iostream>
using namespace std;
int main()
{
	freopen("coins_game.txt","r", stdin);
	freopen ("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=0 ; i<T; i++)
	{
		int jars,coins,target;
		cin>>jars>>coins>>target;
		int eachJarHas = coins/jars;
		int noOfCoinsOverflow = coins%jars;     // they have eachJarHas+1 number of coins
		int answer = 0;
		if(eachJarHas == 0 )
		{
			answer = jars - noOfCoinsOverflow /*misshits*/+target; 
		}
		else
		{
			if(target <= eachJarHas * jars)
			{
				answer = target;
			}
			else
			{
				int filledJars = coins/ (eachJarHas+1);
				int overflow = coins % (eachJarHas+1);
				answer = jars- (filledJars) /* misshits */ + target; 
				
			}
		}
		
		cout<<"Case #"<<i+1<<": "<<answer<<endl;
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}