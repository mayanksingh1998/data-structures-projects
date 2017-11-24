#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
//Node of tree
struct treeNode	
{
   int Salary;
   treeNode *leftchild;
   treeNode *rightchild;
   int frequency;
   int height;
};

typedef treeNode *avlnode;
//class of avl tree
class avltree
{

   public:
	int countnodes(treeNode *root, int lower, int higher);
	void datainsertion(int,avlnode &);
	avlnode datadeletion(int, avlnode &,treeNode *);
	int mindelete(avlnode &);
	avlnode minimum(avlnode);
	avlnode maximum(avlnode);
	int treeheight(avlnode);
	avlnode singleleftrot(avlnode &);
	avlnode doubleleftrot(avlnode &);
	avlnode singlerightrot(avlnode &);
	avlnode doublerightrot(avlnode &);
    treeNode* getClosestNode(treeNode *pRoot, int value)
    {
    treeNode* pClosest = NULL;
    int minDistance = 0x7FFFFFFF;
    treeNode* pNode = pRoot;
    while(pNode != NULL){
        int distance = abs(pNode->Salary - value);
        if(distance < minDistance){
            minDistance = distance;
            pClosest = pNode;
        }

        if(distance == 0)
            break;

        if(pNode->Salary > value)
            pNode = pNode->leftchild;
        else if(pNode->Salary < value)
            pNode = pNode->rightchild;
    }

    return pClosest;
    }
 //preorder printing
    void preorder(avlnode p)
    {   
	if (p!=NULL)
	{
	   cout<<p->Salary<<"-->";
	  preorder(p->leftchild);
	  preorder(p->rightchild);
	}
    }   

//Inorder Printing
    void inorder(avlnode p)
    {   
	if (p!=NULL)
	{
	   inorder(p->leftchild);
	    cout<<p->Salary<<"-->";
	   inorder(p->rightchild);
        }
    }
//		PostOrder Printing
    void postorder(avlnode p)
    {   
        if (p!=NULL)
        {
	   postorder(p->leftchild);
	   postorder(p->rightchild);
	    cout<<p->Salary<<"-->";
	}
    }


};

//		Inserting a treeNode
void avltree::datainsertion(int x,avlnode &p)
{  
   if (p == NULL)
   {
	p = new treeNode;
	p->Salary = x;
	p->leftchild=NULL;
	p->frequency=1;
	p->rightchild = NULL;
	p->height=0;
	if (p==NULL)
		 cout<<"Out of Space";
   }
   else
   {
	if (x<p->Salary)
	{
	   datainsertion(x,p->leftchild);
	   if ((treeheight(p->leftchild) - treeheight(p->rightchild))==2)
	   {
	      if (x < p->leftchild->Salary)
		p=singleleftrot(p);
	      else
		p=doubleleftrot(p);
	   }
	}
	else if (x>p->Salary)
	{
	      datainsertion(x,p->rightchild);
	      if ((treeheight(p->rightchild) - treeheight(p->leftchild))==2)
	      {
		if (x > p->rightchild->Salary)
			p=singlerightrot(p);
		else
			p = doublerightrot(p);
	     }
	}
	else
		p->frequency++;
	}
	int m,n,d;
	m=treeheight(p->leftchild);
	n=treeheight(p->rightchild);
	d=((m > n) ? m : n);
	p->height = d + 1;  
}

//		Finding the Smallest
avlnode avltree::minimum(avlnode p)
{
	if (p==NULL)
	{
	    cout<<"Tree is empty";
	    return p;
	}
	else
	{
	   while(p->leftchild !=NULL)
		p=p->leftchild;
	   return p;
	}
}

//		Finding the Largest
avlnode avltree::maximum(avlnode p)
{
	if (p==NULL)
	{
	   cout<<"Tree is empty";
	   return p;
	}
	else
	{
	   while(p->rightchild !=NULL)
	       p=p->rightchild;
	   return p;
	}
}
int height(struct treeNode *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
// Get Balance factor of node N
int balancings( treeNode *N)
{
    if (N == NULL)
        return 0;
    return height(N->leftchild) - height(N->rightchild);
}

int max(int a, int b)
{
    return (a > b)? a : b;
}
//		Deleting a treeNode
avlnode avltree::datadeletion(int x,avlnode &p,treeNode *root)
{    
	avlnode d;
	if (p==NULL)
	{
	    treeNode *temp;
		temp=getClosestNode(root,x);
          cout<<"\nclosest Salary::";
		  cout<<temp->Salary;
    }
	else if ( x < p->Salary)
	   datadeletion(x,p->leftchild,root);
	else if (x > p->Salary)
	   datadeletion(x,p->rightchild,root);
	else if ((p->leftchild == NULL) && (p->rightchild == NULL))
	{
	   d=p;
	   free(d);
	   p=NULL;
	    cout<<"Salary is deleted !";
	}
	else if (p->leftchild == NULL)
	{
	  d=p;
	  free(d);
	  p=p->rightchild;
	   cout<<" Salary is deleted !";
	}
	else if (p->rightchild == NULL)
	{
	  d=p;
	  p=p->leftchild;
	  free(d);
	   cout<<"Salary is deleted !";
	}
	else
	  p->Salary = mindelete(p->rightchild);


    
     // If the tree had only one node then return
    if (root == NULL)
      return root;
 
    // UPDATing HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->leftchild),height(root->rightchild));
 
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = balancings(root);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && balancings(root->leftchild) >= 0)
        return singlerightrot(root);
 
    // Left Right Case
    if (balance > 1 && balancings(root->leftchild) < 0)
    {
        
        return doublerightrot(root);
    }
 
    // Right Right Case
    if (balance < -1 && balancings(root->rightchild) <= 0)
        return singleleftrot(root);
 
    // Right Left Case
    if (balance < -1 && balancings(root->rightchild) > 0)
    {
        return doubleleftrot(root);
    }
    
    return root;

}

int avltree::mindelete(avlnode &p)
{
	int c;
	
	if (p->leftchild == NULL)
	{
	  c=p->Salary;
	  p=p->rightchild;
	  return c;
	}
	else
	{
	  c=mindelete(p->leftchild);
	  return c;
	}
}


int avltree::countnodes(treeNode *root, int lower, int higher)
{
    // Base case
    if (!root) return 0;
 
    // Special Optional case for improving efficiency
    if (root->Salary == higher && root->Salary == lower)
        return root->frequency;
 
    // If current treeNode is in range, then include it in count and
    // recur for leftchild and rightchild children of it
    if (root->Salary <= higher && root->Salary >= lower)
         return  root->frequency + countnodes(root->leftchild, lower, higher) +
                    countnodes(root->rightchild, lower, higher);
 
    // If current treeNode is smaller than lower, then recur for rightchild
    // child
    else if (root->Salary < lower)
         return countnodes(root->rightchild, lower, higher);
 
    // Else recur for leftchild child
    else return countnodes(root->leftchild, lower, higher);
}



int avltree::treeheight(avlnode p)
{
	int t;
	if (p == NULL)
		return -1;
	else
	{
		t = p->height;
		return t;
	}
}

avlnode avltree:: singleleftrot(avlnode &p1)
{
	avlnode p2;
	p2 = p1->leftchild;
	p1->leftchild = p2->rightchild;
	p2->rightchild = p1;
	p1->height = ((treeheight(p1->leftchild) > treeheight(p1->rightchild)) ? treeheight(p1->leftchild) : treeheight(p1->rightchild)) + 1;
	p2->height = ((treeheight(p2->leftchild)>p1->height)?treeheight(p2->leftchild): p1->height) + 1;
	return p2;
}

avlnode avltree:: singlerightrot(avlnode &p1)
{
	avlnode p2;
	p2 = p1->rightchild;
	p1->rightchild = p2->leftchild;
	p2->leftchild = p1;
	p1->height = ((treeheight(p1->leftchild) > treeheight(p1->rightchild)) ? treeheight(p1->leftchild) : treeheight(p1->rightchild)) + 1;
	p2->height = (p1->height>treeheight(p2->rightchild)?p1->height: treeheight(p2->rightchild)) + 1;
	return p2;
}


avlnode avltree:: doubleleftrot(avlnode &p1)
{
	p1->leftchild=singlerightrot(p1->leftchild);
	return singleleftrot(p1);
}

avlnode avltree::doublerightrot(avlnode &p1)
{
	p1->rightchild = singleleftrot(p1->rightchild);
	return singlerightrot(p1);
}


//MAIN FUNCTION
#include<fstream>
int main()
{   
     ifstream fin;
	avlnode root,min=NULL,max=NULL;
	int a,choice,findle,deletel,value;
	char ch='y';
	avltree atree;
	root = NULL;
	fin.open("rahul.txt",ios::in);
	 cout<<"AVL Tree\n";
	 cout<<"=======\n";
	do
		{
		 cout<<"1.Insertion\n2.Find Minimum salary\n";
		 cout<<"3.Find Maximum salary\n";
		 cout<<"4.Delete Salary\n5.No of people having salary inRange\n";
		 cout<<"";
		 cout<<"\nEnter the choice:";
		 cin>>choice;
	
		{
	    if(choice==1)
	    {	/* cout<<"\n enter no of values:";
			 cin>>choice;
			 cout<<"New treeNode's value ?";
			
			for(int i=0;i<choice;i++){
			 cin>>a;
			atree.datainsertion(a,root);
		} */
		    while(!fin.eof())
		    {
		    	fin>>a;
		    	atree.datainsertion(a,root);
		    }
		    fin.close();
		      cout<<"\n";
			atree.preorder(root);
			  cout<<"\n";
		    atree.postorder(root);
		      cout<<"\n";
		    atree.inorder(root);

	}else if(choice==2){
			if (root !=NULL)
			{
			min=atree.minimum(root);
			 cout<<"Min Salary :	"<<min->Salary;
			}
			}
	else if(choice==3){
	        if (root !=NULL)
            {
			max=atree.maximum(root);
			 cout<<"Max Salary :	"<<max->Salary;
			}
		}
else if(choice==4)	{		 cout<<"Delete Salary ?";
			 cin>>deletel;
			root=atree.datadeletion(deletel,root,root);
		    
}
       
	else if(choice==5){
		     int g,h; cout<<"\nenter the ranges(both)";
		     cin>>g>>h;
		     cout<<"\nNo of people having salary in that range::";
             cout<<atree.countnodes(root,g,h);
        }
        else cout<<"Wrong Choice";
	

}
		
		 cout<<"\nDo u want to continue (y/n) ?";
		 cin>>ch;
	}while(ch=='y');



	return 0;
}
