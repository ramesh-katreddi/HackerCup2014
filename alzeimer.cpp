#include<iostream>
using namespace std;

int findGcd(int n1, int n2){

  int rem;
  if(n2 ==0 ) return n1;
  else if (n1==0) return n2;
  if(n2>n1)
  {
    n1=n1+n2;
    n2=n1-n2;
    n1=n1-n2;
  }
  do
  {
      rem=n1%n2;
      n1=n2;
      n2=rem;
   }while(rem!=0);
  return n1;
}
void checkIfProper(int* numbers, int N , int K , int initial)
{
	bool allSet = true;
	for(int i = 0 ; i< N ; i++)
	{
		bool shouldBreak = false;
		if(numbers[i] == 0) continue;
		for(int j=i+1 ; j<N ; j++)
		{	

			int high = j ,low =i;
			if(numbers[i] > numbers[j])
			{
				high = i;
				low  = j;
			}
			if(numbers[i] == 0 || numbers[j] == 0) continue;
			int gcd = findGcd(numbers[high],numbers[low]);
			if(gcd != K) 
			{
				numbers[high] = numbers[high] + K;
				allSet = false;
			}
		}
	}

	if(!allSet)
	{
		checkIfProper(numbers,N,K,initial);
	}
	else
	{
		int nowCount =0 ;
		for(int i=0 ;i<N ;i++)
		{
			nowCount += numbers[i];
		}
		cout<<nowCount-initial;
	}

}
int main()
{
	freopen("preventing_alzheimers.txt","r", stdin);
	freopen ("output.txt","w",stdout);
	int T;
	cin>>T;
	for(int i=0 ; i<T; i++)
	{
		int N,K;
		cin>>N>>K;
		int *numbers = new int[N];
		int initialSum =0 ;
		bool zeroCame = false;
		for(int j =0;j<N ; j++)
		{
			int number;
			cin>>number;
			
			initialSum = initialSum + number;
			if(number == 0) 
			{	
				if(zeroCame)
					number = K;
				else
					zeroCame = true;
			}
			if(number % K != 0 )
			{
				numbers[j] = ((number/K) + 1 ) * K ;
			}
			else
			{
				numbers[j] = number;
			}

		}
		cout<<"Case #"<<i+1<<": ";
		checkIfProper(numbers,N,K , initialSum);
		cout<<endl;
	}

	fclose(stdin);
    fclose(stdout);
    return 0;
}