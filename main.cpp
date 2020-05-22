/*I use Code::Blocks 17.12 as compiler

This is a typical DFS problem of graph in which I have modified only to count the number of

maximum neighbors in a graph .

i.e

I can have unconnected graphs so I have to just find out a graph which has

maximum connected units so I did in the code.

*/

#include<bits/stdc++.h>

using namespace std;

// This is helper function to which DFS traverse the whole graph with starting node

void find_max_group_UTIL(vector<int> *v, int start, bool* visited,int &maxi){

visited[start] = true;

vector<int> :: iterator it = v[start].begin();

while(it!= v[start].end()){

if(visited[*it] == false){

maxi++; // increment at every visited node

find_max_group_UTIL(v,*it,visited,maxi);

}

it++;

}

}

int find_max_group(vector<int> *v,int n, int start){

bool *visited = new bool[n+1]; // taken a visited array

for(int i=0 ; i<=n ; i++){

visited[i] =false;

}

int maxi = 1; // initialize with at least one element in a group

find_max_group_UTIL(v,start,visited,maxi);

for(int i =1; i<=n; i++){

int temp =1;

if(visited[i] == false){ // for unconnected components we have to traversal full graph

find_max_group_UTIL(v,i,visited,temp);

maxi = max(temp,maxi); // compare for maximum nodes in graph

}

}

return maxi;

}

// adds edge in the graph with given pair of input

void addEdge(vector<int>* v, int a, int b){

v[a].push_back(b);

v[b].push_back(a);

}

int main(){

int t;

cin>>t;

while(t--){ // test cases

int n,m;

cin>>n>>m;



/*assert function to check for invalid input*/

assert(n>=1 && n<=30000);

assert(m>=0&&m<=500000);



vector<int> *v = new vector<int>[n+1]; // array of vectors main graph

int a,b;

for(int i=0; i<m; i++){

cin>>a>>b;

addEdge(v,a,b); // for each input pair we add a edge

}


cout<<"Largest group contains:"; // maximum people in the largest group
cout<<find_max_group(v,n,1) <<" people"<<endl; // call to find output or DFS traversal

}

return 0;

}

