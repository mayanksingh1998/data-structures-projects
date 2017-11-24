#include<iostream>
using namespace std;

class queue{
	int front,rear,n,*b;   
	public:

	queue(int a)           
	{	front=-1;
		 rear=-1;
		 n=a;
 		b=new int[n];   
	}

	void enqueue(int x)     
	{if(rear!=n)
 	  {
           rear++; 
           b[rear]=x;
          }
	}

	int dequeue()           
        {
	if(front!=rear)
	{
          front++;
 	  int k;
          k=front;
          return b[k];          
        }
        }
    };


class stack{                    		         
	int top,n,*c;           
	public:

	stack(int z)               
	{
          top=-1;
	  n=z;
	  c=new int[n];
	}

	void push(int x)           
	{ if(top!=n)
	  {top++;
	   c[top]=x;
	  }
	}

	int pop()                  
	{ top--;
	  int k;
	  k=top+1;
	  return c[k];
	}
       int empty()
       {if(top==-1)
         return 1;
        else
          return 0;
        }
        
        int topelement()
      { return c[top];
      }
     };

int main()
{	int n;
	cout<<"Enter the size of the queue:\n";
	cin>>n;
	int x,p,a[n];              
	queue q1(n),q2(n);         
	stack s(n);                

	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++)
	{ cin>>x;
	  q1.enqueue(x);
	}

	cout<<"Enter the permutation\n";
	for(int i=0;i<n;i++)
	{cin>>a[i];
	}

	int i=0,g=0,u;

	 for(int t=0;t<n;t++)                                              
	  {	p=q1.dequeue(); 
	  	if(p==a[i])
	   	{
		 q2.enqueue(p);i++;    
         
	   	}
               else {if(s.empty()==0) 
                     {u=s.topelement(); 
                  if(u==a[i])
                 { u=s.pop();n++;
                   q2.enqueue(u);g--;i++;
                 }                
                 
          
 		else   		
		{ s.push(p);g++;     
	  	 
		}
                 }
               else
                { s.push(p);g++;      
                
                }

   	 }}

	  while(g!=0)
	  {
		p=s.pop();           
		if(p==a[i])
		{
		q2.enqueue(p);i++;g--;
                
   		}
               else {
         cout<<"\nThis is not  stack permutation"<<" Because at "<<i+1<<"location output queue has"<<p<<"instead of"<<a[i]<<"\n"; 
		  break;                     
                    }
         }  

       if(g==0)
       cout<<"\nThis is stack permutation\n";
       return 0;
}
