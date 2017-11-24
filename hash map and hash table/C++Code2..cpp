#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>

using namespace std;

string k[1000];
void sort(int freq[]){
	int l,j;
	string m;

	for (int i = 0; i < 1000; i++)
	{
		l=freq[i];
		m=k[i];
		for (j=i-1;j>=0 && l<freq[j]; j--)
		{
			freq[j+1]=freq[j];
			k[j+1]=k[j];
		}
		freq[j+1]=l;
		k[j+1]=m;
	}

}



int HashMape(string s){
	int index=0;

	for (int i = 0; i <s.length() ; i++)
	{
		if(int(s[i])<91 && int(s[i])>64)
			s[i]=s[i]+32;
		index=index+(i+1)*int(s[i]);

	}
	index=index%499;
	return index;
}


int main(){

int m=1;
char filename[20];
string str[100]={};
int frequency[1000]={0},threshold;

cout<<"Enter filename(with extension) ::";
cin>>filename;
cout<<"\nEnter threshold ::";
cin>>threshold;
cout<<"\n";
	#ifndef ONLINE_JUDGE
     freopen(filename, "r", stdin);
    #endif



for (int i = 0; i < 100; i++){
	cin>>str[i];
	int temp=str[i].length();
	if(str[i][temp-1]==',' || str[i][temp-1]=='.' || str[i][temp-1]=='-' ||str[i][temp-1]=='!'||str[i][temp-1]=='?' )
	{
		str[i]=str[i].substr(0,temp-1);
	}
	else if(str[i][0]=='"'){
		str[i]=str[i].substr(1,temp-1);
	}
	if(str[i]!=""){
	frequency[HashMape(str[i])]++;
	k[HashMape(str[i])]=str[i];
}
}

sort(frequency);
int l=0;
for (int i = 999; i>=0; i--){
	if(frequency[i]>threshold)
	{
	if(l==0)
	{
		cout<<"Words with their frequencies are::\n";
		l++;
	}
	
	cout<<k[i]<<":"<<frequency[i]<<endl;
    m=0;
    }
}

if(m==1)
{
	cout<<"\nThere is nothing to show (exceeded frequency)";
}


    getch();
    return 0;
}
