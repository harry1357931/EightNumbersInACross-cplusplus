/** 8_NumberIn_A_CrossRecursion  --- Using Recursion
 *  8_NumberIn_A_CrossRecursion.cpp
 *     
 *  Fall, 2011
 *
 *  Problem: 8_NumberIn_A_CrossRecursion
 *     This program allocates the integers 1-8 to the squares in the figure shown in file 'EightNumbersInA_CrossProblem.pdf' , 
 *     subject to the restrictions that no two adjacent squares contain consecutive integers. By adjacent we mean vertically, 
 *     horizontally, or diagonally.     
 *  
 *  For More Description & Example of Problem:
 *     Check File: 'EightNumbersInA_CrossProblem.pdf' 
 *      
 *  Input Format: 
 *       Nothing to Input, just run the program
 *  OutPut Format:
 *      This program will output the '8 numbers in a cross', as shown in figure in file 'EightNumbersInA_CrossProblem.pdf'
 *
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013  
 * @author Gurpreet Singh
 */    
#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;

bool ok(int* a, int c)
{
	int h[8][5]={{-1,-1,-1,-1,-1},
                    {0,-1,-1,-1,-1},
                    {1,-1,-1,-1,-1},
                    {0,1,2,-1,-1},
                    {1,2,3,-1,-1},
                    {2,4,-1,-1,-1},
                    {0,3,4,-1,-1},
                    {3,4,5,6,-1}}; 
	for(int i=0; i<c; i++)
	{
		if(a[c] == a[i])
		{
			return false;
		}
	}
	for(int j=0; j<4; j++)
	{
		if(abs(a[c]-a[h[c][j]])==1)
		{
			return false;
		}
	}
	return true;
}

void print(int* a)
{
	static int count = 0;
	count++;
	cout<<"Formation "<<count<<":\n";
	cout<<" "<<a[1]<<a[2]<<" "<<endl;
	cout<<a[0]<<a[3]<<a[4]<<a[5]<<endl;
	cout<<" "<<a[6]<<a[7]<<endl;
	cout<<endl;
}

void set(int* a,int c)
{
	if(c == 8)
	{
		print(a);
		return;
	}
	for(int j=1; j<9; j++)
	{
		a[c] = j;
		if(ok(a,c))
		{
			set(a,c+1);
		}
	}
};

int main()
{
	int a[8];
	set(a,0);
	system("pause");
	return 0;
}
