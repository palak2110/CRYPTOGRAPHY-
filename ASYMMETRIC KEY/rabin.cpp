#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int fast_exp(int c,int p,int n);

int crt(int a,int b,int c,int d);
int main()
{
	int a,b,n,p,q;
	int a1,a2,b1,b2,p1,q1,at,bt;
	int ct,pt;
	cout<<"enter p & q: ";
	cin>>p>>q;
	n=p*q;
	cout<<n;

	
	cout<<"\nenter plain text: ";
	cin>>pt;

	ct = (pt*pt)%n;
	cout<<"the cipher text is: \n"<<ct;
	//Decryption
	p1=(p+1)/4;
	q1=(q+1)/4;	

	a1 = fast_exp(ct,p1,p);
	a2 = p-a1;
	b1 = fast_exp(ct,q1,q);
	b2 = q-b1;



	cout<<"\na1 : "<<a1<<"\na2: "<<a2<<"\nb1: "<<b1<<"\nb2: "<<b2;
	int p11 = crt(a1,b1,p,q);
	int p2 = crt(a1,b2,p,q);
	int p3 = crt(a2,b1,p,q);
	int p4 = crt(a2,b2,p,q);
	cout<<"\nP1: "<<p11;
	cout<<"\nP2: "<<p2;
	cout<<"\nP3: "<<p3;
	cout<<"\nP4: "<<p4;

	if(p11 == pt)
	{
		cout<<"\nDecrypted: "<<p11;
	}
	else if(p2 == pt)
	{
		cout<<"\nDecrypted: "<<p2;
	}
	else if(p3 == pt)
	{
		cout<<"\nDecrypted: "<<p3;
	}
	else if(p4 == pt)
	{
		cout<<"\nDecrypted: "<<p4;
	}

}

int modInverse(int a, int m) 
	{ 
    	a = a%m; 
    	for (int x=1; x<m; x++) 
       		if ((a*x) % m == 1) 
        		return x; 
	} 
int fast_exp(int c,int d,int n)
	{
		int k=1;
		for(int i=0;i<d;i++)
		{
			
			k=k*c;
			k=k%n;


		}
		return k;
		
		
	}

int crt(int a,int b,int c,int d)
{
	int n = c*d;
	int c1 = n/c;
	int d1 = n/d;

	int cinv = modInverse(c1,c);
	int dinv = modInverse(d1,d);

	int x = ((a*c1*cinv)+(b*d1*dinv))%n;
	return x;
}
