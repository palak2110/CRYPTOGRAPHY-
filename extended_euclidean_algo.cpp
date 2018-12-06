#include<iostream>
using namespace std;

int main()
{
    int r1,r2,t1=0,t2=1,s1=1,s2=0,s,r,t,q,a,m;
    cout<<"Enter a and m: ";
    cin>>a>>m;

    r1=a;
    r2=m;

    while(r2>0)
    {
        q = int(r1/r2);
        r = r1 - q*r2;
        s = s1 - q*s2;
        t = t1 - q*t2;
        r1=r2;
        r2=r;
        
        s1=s2;
        s2=s;
        
        t1=t2;
        t2=t;
        cout<<"\nq "<<q<<"\n"<<"r1 "<<r1<<"\n"<<"r2 "<<r2<<"\n"<<"r "<<r<<"\n"<<"s1 "<<s1<<"\n"<<"s2 "<<s2<<"\n"<<"t1 "<<t1<<"\n"<<"t2 "<<t2<<"\n"<<"t "<<t;
    

    }
        if(r1==1)
        {
            cout<<"The multiplicative inverse is: "<<t1;
        }
        else
        {
            cout<<"Mulitiplicative inverse not possible";
        }

    return 0;
}
