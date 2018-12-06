	#include<iostream>
	#include<cstdlib>
	#include<cmath>
	#include<cstring>
	#include <typeinfo>
	
	using namespace std;
	int checkprime(int a,int b);
	int checkE(int e,int n,int p,int q);
	int modInverse(int a,int m);
	int fast_exp(int c,int d,int n);
	int main()
	{
		int a,b,e,phin,k=1,i;
		int msg,n;
		long int en,dn,en1,dn1;
		long int d;
		cout<<"\nenter a & b ";
		cin>>a;
		cin>>b;
		checkprime(a,b);
		n=a*b;
		cout<<"\nThe public key (n) is: "<<n;
		cout<<"\nenter e: ";
		cin>>e;
		e,phin = checkE(e,n,a,b);
		cout<<"\nPublic values are n: "<<n<<" e: "<<e;
		//private key
		cout<<"\n"<<phin;
		d = modInverse(e,phin);
		cout<<"\nd is: "<<d;

		cout << "\nenter message\n";
   	    cin >> msg;
	    
   	    en = pow(msg,e);
   	    
   	    en1 = en % n;
   	    cout<<en1;
		
		
		cout<<"\n"<<fast_exp(en1,d,n);
        return 0;
		
		

	}
	int modInverse(int a, int m) 
	{ 
    	a = a%m; 
    	for (int x=1; x<m; x++) 
       		if ((a*x) % m == 1) 
        		return x; 
	} 
	int checkprime(int a,int b)
	{
		int count,i,a1,b1;
		if (a == 0)
	    {
	        
	        cout<<"a can't be 0";
	        exit(0);
	    }
	    else   
	    {
	            for(i=2; i < a; i++)
	                if (a % i == 0)
	                    count++;
	    }
		if (count > 1)
		{
	 	    cout << "\n" << a << " is not prime.";
	 	    exit(0);
	 	    

	 		
	    }
	    else
	        cout << "\n" << a << " is prime.";

	    if (b == 0)
	    {
	        cout << "\n" << "b can't be 0";
	        exit(0);
	        
	        
	    }
	    else   
	    {
	            for(i=2; i < b; i++)
	                if (b % i == 0)
	                    count++;
	    }
		if (count > 1)
		{
	 	    cout << "\n" << b << " is not prime.";
	 	    exit(0);
	 	    
	       	
	    }
	    else
	        cout << "\n" << b << " is prime.";

	    return a,b;
	   	
	}

	int checkE(int e,int n,int p,int q)
	{
		int e1;

		int phin = (p-1)*(q-1);
		
		if(e > 1 && e < phin && (n%e!=0))
		{
			cout<<"E is valid";
			
		}
		else
		{
			cout<<"Invalid";
			exit(0);
			
		}
		
		return e,phin;

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
