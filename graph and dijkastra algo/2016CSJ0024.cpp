// A C++ Program 
#include<iostream>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<fstream>
 using namespace std;


int prev[100];
bool visited[100];
//used for visited nodes
int D[100];
//used for saving updated distance

// A structure to represent an adjacency list node
struct VNode
{   //flight details 
    int city2;
    char flight[20];
    int price;
    int departure;
    int arrival;
    struct VNode* next;
};

// A structure to represent an adjacency list
struct HeadNode
{   //vertex details
    int city1;
    struct VNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct HeadNode* array;
};
 
// A utility function to create a new adjacency list node
struct VNode* newVNode(int city2,int dept,int arrival,int price,char flight[20])
{   //used for making new nodes
    struct VNode* Node = (struct VNode*) malloc(sizeof(struct VNode));
    Node->arrival=arrival; 
    Node->city2 = city2;
    Node->departure=dept;
    strcpy(Node->flight,flight);
    Node->price=price;
    Node->next = NULL;
    return Node;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{   
    //creating graph
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct HeadNode*) malloc(V * sizeof(struct HeadNode));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i=0;
    while(i<=V)
    {
    	graph->array[i].head = NULL;
    	graph->array[i].city1 =-1;
		++i;
	}
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest,int price,int arrival,int departure,char flight[20])
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct VNode* newNode = newVNode(dest,departure,arrival,price,flight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    graph->array[src].city1=src;
	
	// for initialiazing all the vertexes
    if(graph->array[dest].head==NULL)
    {
    	graph->array[dest].city1=dest;
	}
 
}
 
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{    
    int v;
    
	for (v = 0; v <= graph->V; ++v)
    {
    	
     if(graph->array[v].head!=NULL){
	 
		struct VNode* pCrawl = graph->array[v].head;
        if(graph->array[v].head==NULL)
         continue;
        
        if(graph->array[v].head!=NULL)
         cout<<"\n"<<graph->array[v].city1<<"->";
     
	 while(pCrawl)
		{    
            cout<<" "<<pCrawl->arrival;
            cout<<" "<<pCrawl->city2;
            cout<<" "<<pCrawl->departure;
            cout<<" "<<pCrawl->flight;
            cout<<" "<<pCrawl->price;
            cout<<"  ->";
            pCrawl = pCrawl->next;
            
        }
        
        printf("\n");
      }
      
	}
}

//for initializing visting and distance array
void initialize(int a,int s,struct Graph* graph){
	
	for(int i=0;i<=a;i++)
	{   
	    
		visited[i]=false;
		D[i]=78912749;
		prev[i]=-1;
		
	}
	D[s]=0;
}

//for selecting unvisited and minimum distance nodes
int minimum(struct Graph* graph,int a){
	int ind=1,min,c=0;
	int index;
	//slecting minimum ditance  of unvisited nodes
	while(ind==1)
	{
		if(visited[c]==false)
		 {
		 	min=D[c];
		 	ind=0;
		 }
		 c++;
	}
	for(int i=0;i<=a;i++){
		
		if(visited[i]==false&&D[i]<min)
		 {  
		    min=D[i];
		 	index=i;
		 }
		 else if(D[i]==min)
		 {
		 	index=i;
		 }
		 
	}
	
	return index;
	
}
int fd=0;
//length of distance between nodes
int length(struct Graph* graph,int i, int w,int arv,int dep){
	
	int min=78912750,lmd;
	struct VNode* pCrawl = graph->array[i].head;
	while(pCrawl)
		{   
		    if(pCrawl->city2==w) 
		     {   
			    
			      if(min>pCrawl->price&&(pCrawl->arrival<=arv&&pCrawl->departure>=dep))
		           {
				   	           	   min=pCrawl->price;
				   }
					   }      
		    pCrawl = pCrawl->next;
            
        }
    return (min);
}
//shortest path withi the time range
int shortestpath(int a,struct Graph* graph,int source,int dest,int arv,int dep){
	int i=1,x,w;
	while(i<=a)
	{
	
	x=minimum(graph,a);
	
	visited[x]=true;
	struct VNode* pCrawl = graph->array[x].head;
	if(graph->array[x].head==NULL)
	 visited[x]=1;
	while (pCrawl)
        {   
            w=pCrawl->city2;
            
           
			 if((visited[w]==false)&&(D[w]>(D[x]+length(graph,x,w,arv,dep)))&&length(graph,x,w,arv,dep)!=78912750)
            {
            	D[w]=D[x]+length(graph,x,w,arv,dep);
				prev[w]=x;
				if(D[w]>=78912749)
				{
					D[w]=78912749;
				}
			}
		    
		    
            pCrawl=pCrawl->next;
        } 
	 i++;
	}	
}

//main function
 int main()
 {  int V ,m,x,b,v,c,lk;
    fstream fin;
    fin.open("file.txt",ios::in);
	char s[10];
    fin>>V;
    int i=0;
    fin>>lk;
	struct Graph* graph = createGraph(V);
 //adding an edge 
    while(i<lk){
	fin>>m;
	fin>>x;
	fin>>c;
	fin>>b;
	fin>>s;
	fin>>v;
    addEdge(graph, m,x,v,b,c,s);
    i++;
	}
	
	int arrival,dept;
    int n,g,nd;
    fin>>nd;
    i=0;
    //queries
    while(i<nd){
    fin>>n;
	fin>>g;
	fin>>dept;
	fin>>arrival;	
	initialize(V,n,graph);
    shortestpath(V,graph,n,g,arrival,dept);
	if(D[g]==78912749)
	cout<<"-1\n";
	else cout<<D[g]<<"\n";
    i++;
	}
	
    getch();
    return 0;
}
