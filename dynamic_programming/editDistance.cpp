/*
Given two strings s and t of lengths m and n respectively, 
find the Edit Distance between the strings. Edit Distance of 
two strings is minimum number of steps required to make one string equal to other.
 In order to do so you can perform following three operations only :

1. Delete a character

2. Replace a character with another one

3. Insert a character
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

//using recursion
int editDistance_rec(string s1, string s2)
{
    if(s1.length() == 0)      //s2 ="abc" , s1=""  ->3 insertions or 3 deletions will be performed (3 = s2.length) 
        return s2.length();
    if(s2.length() == 0)
        return s1.length();
    if(s1[0] == s2[0])
        return editDistance_rec(s1.substr(1),s2.substr(1));
    else
    {
        int x = 1 + editDistance_rec(s1.substr(1),s2); 				// assuming s1[0] is inserted in front of s2
        int y = 1 + editDistance_rec(s1.substr(1),s2.substr(1)); 	//s1[0] is replaced with s2[0]
        int z = 1 + editDistance_rec(s1,s2.substr(1));   			// assuming s2[0] is deleted
        return min(x,min(y,z));
    }

}
//using memoisation
int editDistance_memHelper(string s1,string s2,int **output)
{
    int m = s1.length();
    int n = s2.length();
    if(m==0 || n==0)
    {
         output[m][n] = max(m,n);
        return output[m][n];
    }
    //check if already calculated
    if(output[m][n]!= -1)
        return output[m][n];
    //small calculation
    int ans;
    if(s1[0] == s2[0])
    {
        ans = editDistance_memHelper(s1.substr(1),s2.substr(1),output);
    }
    else
    {
        output[m-1][n-1] = editDistance_memHelper(s1.substr(1),s2.substr(1),output);
        output[m-1][n] =  editDistance_memHelper(s1.substr(1),s2,output);
        output[m][n-1] =  editDistance_memHelper(s1,s2.substr(1),output);
        ans = 1 + min(output[m][n-1],min(output[m-1][n-1],output[m-1][n]));
    }
    output[m][n] = ans;
    return ans;
}
int editDistance_mem(string s1,string s2)
{
 int m = s1.length();
 int n = s2.length();
int **output = new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++)
            output[i][j] = -1;
    }
    
	return editDistance_memHelper(s1,s2,output);
}  
//**************** using dp******************************************************//

int editDistance_dp(string s1,string s2)
{
   	int m=s1.length();
	int n=s2.length();
	int **output = new int *[m+1];
	for(int i=0;i<= m;i++)
	{
		output[i] = new int[n+1];
	}
    // in output[i][j] -> i=length of s1 , j= length of s2.
    // when s1 is of length 0 , no of operations required = length of s2 at that time.
    for(int i =0;i<=n;i++)
        output[0][i] = i;
     // when s2 is of length 0 , no of operations required = length of s1 at that time.
    for(int i =0;i<=m;i++)
        output[i][0] = i;
    // filling subsequent rows  left to right ,top->bottom ,.
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ans = min(output[i-1][j-1],min(output[i-1][j],output[i][j-1]));
            if(s1[m-i] == s2[n-j])      //think over it , take help from the editDistance_rec function
                output[i][j] = ans;
            else
                output[i][j] = 1 + ans;
        }
    }
    return output[m][n];
}   
int main()
{
    string s1,s2;
    cout<<endl<<"enter strings - ";
    cin>>s1>>s2;
    cout<<"minimum no of operations require to make the strings equal = "<<"\n1.using memoisation ->"<<editDistance_mem(s1,s2)<<endl;
    cout<<"2.using dp = "<<editDistance_dp(s1,s2)<<endl;
    cout<<"3.using recursion ="<<editDistance_rec(s1,s2);
}