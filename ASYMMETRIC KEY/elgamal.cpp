#include<iostream>
using namespace std;


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
int main()
{
	int p,d,e1,e2;
	//key gen
	cout<<"\nEnter p: ";
	cin>>p;
	cout<<"\nEnter d: ";
	cin>>d;
	cout<<"\nEnter e1: ";
	cin>>e1;
	int pt;
	cout<<"\nEnter plain text: ";
	cin>>pt;
	e2 = fast_exp(e1,d,p);
	cout<<"\nPublic key: "<<e1<<" "<<e2<<" "<<p;
	cout<<"\nPrivate key: "<<d;

	//encryption
	int r;
	cout<<"\nEnter r: ";
	cin>>r;

	int c1 = fast_exp(e1,r,p);
	int c2 = fast_exp((fast_exp(pt,1,p)*fast_exp(e2,r,p)),1,p);

	cout<<"\nCipher text: "<<c1<<" "<<c2;

	//Decryption

	int P;

	P = fast_exp(fast_exp(c2,1,p)*fast_exp(c1,p-1-d,p),1,p);

	cout<<"\nDecryption: "<<P;


}
