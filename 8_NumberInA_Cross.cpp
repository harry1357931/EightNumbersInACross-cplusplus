/** 8_NumberIn_A_Cross Problem --- Without using Recursion
 *  8_NumberInA_Cross.cpp
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

#include <iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
int large (int array1[])
{
    int largest=0;
    for (int i=0;i<=7;i++) 
       {   if (array1[i]>=largest)
           largest=array1[i];
           
             
       }    // for i-loop                                 
    
     return largest;
}  // function "large" ends here
int main()
{
  int i,j,k,l,q[8]={0},a[8][5]={0},x;
  int array[8]={1,2,3,4,5,6,7,8};
  
  
  a[0][0]=-1; a[1][0]=0;a[1][1]=-1;a[2][0]=1;a[2][1]=-1;a[3][0]=0;
  a[3][1]=1;a[3][2]=2;a[3][3]=-1; a[4][0]=1;a[4][1]=2;
  a[4][2]=3;a[4][3]=-1; a[5][0]=2;a[5][1]=4;
  a[5][2]=-1;a[6][0]=0;a[6][1]=3;a[6][2]=4;a[6][3]=-1;a[7][0]=3;
  a[7][1]=4;a[7][2]=5;a[7][3]=6;a[7][4]=-1;
  
  
  for(i=0;i<=7;i++)        // begining of i-for loop...to assign values to q[i]....cross values
  {  k=0;
      love:for(l=k;l<=7;l++)                      //Assigning Value to q[i] one by one....from array[l]
       {
          backtrack:if(array[l]!=0)
             {
                q[i]=array[l];                    // Assigning values to q[i] ...for further tests
                break;                           // break from L-for loop after assigning values.
             }                                     
          }  
              
                
      
       for(j=0;j<=4;j++)   
        {  if (a[i][j]==-1)
           break;
           if(abs(q[i]-q[a[i][j]])==1)      //  Use Magnitude sign or use || and -1
             { 
               if(l!=8)          //need some condition...if statement
               {k=l+1;
               goto love;}
               if(l==8)         
               { againb :i--;
                 array[(q[i]-1)]=q[i];
                 l=q[i];
                 x=large(array);       //find x using code for x here....x=current greatest value in array.
                 if(q[i]==x)          //find the greatest value(x) in array[] and compare it with q[i]....use current greatest value code
                   goto againb;            // a kind of double backtrack.
                 goto backtrack;      // backtrack is needed if no number from available array fits in q[i] ...for L-loop
               } // if (l==8) ends here
             }   //if abs(q[i]-q[a[i][j]]==1)                 
        }  // for J-loop ends here
         array[l]=0;      //  Setting values to zero which are  assigned and tested...
                         
         
  }// for loop i  ends here
  
  cout<<"  "<<q[1]<<" "<<q[2]<<endl;
  cout<<q[0]<<" "<<q[3]<<" "<<q[4]<<" "<<q[5]<<endl;
  cout<<"  "<<q[6]<<" "<<q[7]<<endl;  
 
      
  system("pause");
  return 0;  
    
 } 
  

  
