#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

struct myStruct {
  int shotPercent;
  int height;
  string name;
  myStruct(){}
  myStruct(const string& n, int a , int b)
		: name(n), shotPercent(a),height(b){}

};
std::set<std::string> sortedItems;

/*
5
6 3 2
Wai 99 131
Weiyan 81 155
Lin 80 100
Purav 86 198
Slawek 80 192
Meihong 44 109
7 93 2
Paul 82 189
Kittipat 62 126
Thomas 17 228
Fabien 57 233
Yifei 65 138
Liang 92 100
Victor 53 124
*/
bool compare(const myStruct& first, const myStruct& second)
{
	if(first.shotPercent == second.shotPercent)
	{
		if(first.height > second.height) 
			return true;
		else
			return false;
	}
	else if (first.shotPercent > second.shotPercent)
		return true;
	else
	    return false;
}
void print(const std::string& item)
{
    std::cout << " "<<item ;
}
void SelectPlayersfromTeamAndInsert(int requiredIndex, int cntActive, int cntTeam, list<myStruct> players, bool isEven)
{
		/* our index is greater than our active players.. so all of them would have been replaced*/
		if(requiredIndex >= cntActive)
		{
			/* so do we have enough number of non-active players or do we have to get some of our old players back  */
			if( requiredIndex + cntActive <= cntTeam)
			{	
				std::list<myStruct>::iterator it = players.begin(); //already at 1
				if(isEven) it++;//in this case at 2
				std::advance(it, 2*(requiredIndex-1));  //ALREADY we surpassed one 
			
				for(int i=0; i< cntActive ; i++)
				{
					myStruct temp = *it;
					sortedItems.insert(temp.name);
					if(i != cntActive)
					{
						it++;
						it++;
					}
				}
			}/* So now we have some numbers from nonactive and some from already played and den sat and went back */
			else if(requiredIndex + cntActive > cntTeam)
			{
				std::list<myStruct>::iterator it = players.begin();
				if(isEven) it++;
				std::advance(it, 2*(requiredIndex));
				for(int i =0 ;i< cntTeam - requiredIndex ;i++)
				{
					myStruct temp = *it;
					sortedItems.insert(temp.name);
					if(i!=  cntTeam - requiredIndex-1)
					{
						it++;
						it++;
					}	
				}
				it = players.begin();
				if(isEven) it++;
				std::advance(it,2*( cntTeam-requiredIndex) );
				for(int i=0 ;i< cntActive + requiredIndex -cntTeam ;i++)
				{
					myStruct temp = *it;
					sortedItems.insert(temp.name);
					if(i != cntActive + requiredIndex-1  ){
						it++;
						it++;				
					}
				}
			}

		}/* this case is some of the active players are still there bench players are coming in slowly*/
		else if(requiredIndex < cntActive)
		{
			std::list<myStruct>::iterator it = players.begin();
			
			if(isEven) it++;
			for(int i=0; i<= cntActive - requiredIndex ; i++)
			{
				myStruct temp = *it;
				sortedItems.insert(temp.name);
				if(i!=  cntActive - requiredIndex -2)
				{
					it++;
					it++;
				}
			}
					
			it = players.begin();
			if(isEven) it++;
			if(cntTeam > cntActive)
			{	
				std::advance(it, 2*(cntActive-1));
			}
			else if (cntTeam == cntActive)
			{
				std:advance(it,2*(cntActive-requiredIndex));
			}
			for(int i=0 ;i< requiredIndex-1 ; i++)
			{
				myStruct temp = *it;
				sortedItems.insert(temp.name);
				if(i!=  requiredIndex - 2)
				{
					it++;
					it++;
				}
			}
			/*		bench players were there and slowly its moving towards active players*/
		}
}
/*

HERE WE WROTE IT AS 5(1) 

solution follows this logic:

it just follows cycle as shown in pic CAM00312       

N = 7 and p = 4 in our case.. let us say m is the minute we need to find out.

Reverse Array of (P to N)  + (0 to P) --> (13 11 9) +(1 3 5 7)  --> this is circular

position = m % N 
 
13 11 9 1 3 5 7 --> initial pointer will be at 1 (m=0) for each increment in minute.. pointer moves one element left side Circular (Check the pic).

print P elements from A[(N-P)-position]   ( remember its circular).

*/
int main()
{
	freopen("input.txt","r", stdin);
	freopen ("output.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0 ; i<n ;i++)
	{
		int noOfPlayers,minute,noOfActivePlayers;
		cin>>noOfPlayers;
		cin>>minute;
		cin>>noOfActivePlayers;
		list<myStruct> players;
		for(int j=0; j<noOfPlayers ; j++)
		{
			string name;
			int shot,height;
			cin>>name;
			cin>>shot;
			cin>>height;
			players.push_back(myStruct(name,shot,height));
		}
		players.sort(compare);
		int team1Count = noOfPlayers/2;
		int team2Count = noOfPlayers/2;
		if(noOfPlayers % 2 == 1) team1Count++;
		
		//odd players
		int requiredIndexFirst = minute %team1Count;
		int requiredIndexSecond = minute %team2Count;
		
		SelectPlayersfromTeamAndInsert(requiredIndexFirst,  noOfActivePlayers,  team1Count, players,false);
		SelectPlayersfromTeamAndInsert(requiredIndexSecond,  noOfActivePlayers,  team2Count, players,true);

		cout<<"Case #"<<i+1<<":";
		std::for_each(sortedItems.begin(), sortedItems.end(), &print);
		cout<<endl;
		sortedItems.clear();
		
	}

	
	fclose(stdin);
    fclose(stdout);
    return 0;
}