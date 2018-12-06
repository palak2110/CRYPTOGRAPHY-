#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	int i,j,k,key[3][3],mat[3][1],s=0,arr2[3][1],mat2[3][1];

	char arr[3][1],mat3[3][1];
	cout<<"\nEnter plain text: ";

	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
			cin>>arr[i][0];
	}
	//Encryption
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)

		{
			arr2[i][j]=(int)arr[i][j]-65;
		}
		
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			cout<<arr2[i][j];
		}
		cout<<'\n';
	}


	cout<<"\nenter key: \n ";

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>key[i][j];
		}
	}


	cout<<"\n key is: \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<" "<<key[i][j];
		}
		cout<<"\n";
	}



	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			{
				//cout<<key[i][j]<<" \n"<<arr2[j][0]<<"\n";
				s=s+key[i][j]*arr2[j][0];
				//cout<<" "<<s;
			}
			
		}
		mat[i][0]=s;
		s=0;
	}




	cout<<"\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			cout<<" "<<mat[i][j];
		}
		cout<<"\n";
	}




	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			mat2[i][j]=mat[i][j]%26;
		}
		cout<<"\n";
	}



	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
				mat3[i][j] = char(mat2[i][j]+65);
				cout<<" "<<mat2[i][j]<<" The encrypted key is: "<<mat3[i][j];
		}
		cout<<"\n";
	}


	

   return 0;
}







