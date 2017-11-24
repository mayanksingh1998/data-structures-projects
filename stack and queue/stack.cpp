#include<iostream>
#include<conio.h>

using namespace std;

template <class T>
class stack
{   private:
  int N,top;
   T A[100];
   T element;
   
   
   public: 
   stack(){
   	N=10;
   	top=-1;
   }
 void push(T element);
 void pop();
 bool isempty();
 bool isfull();
 void tope();
 }  ;
 template <class T>
  void stack<T>:: push(T element)
    {
    	if(isfull()==1)
    	{cout<<"Stack is full";}
	else {
		A[top++]=element;
		 
	
	}
}
template <class T>
void stack<T>::pop(){
	if(isempty()==1)
	{
		cout<<"stackis empty";
	}
	else
	{   
		top--;
		for(int i=0;i<=top;i++)
		{
		cout<<"\n"<<A[i];
}
	}}
	template <class T>
	bool stack<T>::isempty()
	{
		if(top==-1)
		{return 1;}
		else 
		 return 0;
	}
	template <class T>
	bool stack<T>::isfull()
	{
		if(top==(N-1))
		{
			return 1;
		}
		else return 0;
	}
template <class T>
void stack<T>::tope(){
		cout<<"\n"<<A[top];
}




int main()
{   
    stack<int>  B;
	stack<char> b;
	B.push(1);
	B.push(2);	
	B.push(10);
	b.push('a');
	
	
}

