#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

void check(vector<int>& virus, vector<vector<int>>adjac, unordered_set<int> s, int distance)
{
 for(int i=1; i<virus.size();i++)
 {
  if(s.find(i)!=s.end())
  {
   queue<pair<int,int>>q;
   unordered_set<int>us;
   us.insert(i);
   q.push(make_pair(i,distance));
   while(!q.empty())
   {
    pair<int,int>current=q.front();
    q.pop();
    virus[current.first]++;
    for(int j=0; j<adjac[current.first].size();j++)
    {
     if(current.second>=1 && us.find(adjac[current.first][j])==us.end())
     {
      q.push(make_pair(adjac[current.first][j],current.second-1));
      us.insert(adjac[current.first][j]);
     }
    }
   }
  }
 }
	
}

int main() {
 int cities,hotspot, distance;
 cin>>cities;
 cin>>hotspot;
 cin>>distance;
 unordered_set<int>s;
 for(int i=0;i<hotspot;i++)
 {
  int a;
  cin>>a;
  s.insert(a);
 }
 vector<int>virus(cities+1,0);
 vector<vector<int>>adjac(cities+1);
 for(int i=0; i<cities-1;i++)
 {
  int a;
  int b;
  cin>>a;
  cin>>b;
  adjac[a].push_back(b);
  adjac[b].push_back(a);
 }
	
 check(virus,adjac,s,distance);
 int count=0;
 int hotspotcover=s.size();
 for(int i=0;i<virus.size();i++)
 {
  if(virus[i]==hotspotcover)
   count++;
 }
 cout<<count;
 return 0;
}
