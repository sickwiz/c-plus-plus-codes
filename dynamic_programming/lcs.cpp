#include<bits/stdc++.h>
using namespace std;
//lcs = longest consecutive subsequence
// using recursion
int lcs(string s1,string s2)
{
    if(s1.length() == 0 || s2.length() == 0)
        return 0;
    if(s1[0] == s2[0])
       {
        //    string newOutput = output + s1[0];
           return 1 + lcs(s1.substr(1),s2.substr(1));
       }
     int len1 = lcs(s1.substr(1),s2);
     int len2 = lcs(s1,s2.substr(1));
        return max(len1,len2);
}
// using memoization
int lcs_mem(string s, string t, int **output) //overloaded function
{
	int m = s.size();
	int n = t.size();
	
	// Base case
	if(s.size() == 0 || t.size() == 0) {
		output[m][n] = 0;
		return 0;
	}

	// Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

	int ans;
	// Recursive calls
	if(s[0] == t[0]) {
		ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
	}
	else {
		int a = lcs_mem(s.substr(1), t, output);
		int b = lcs_mem(s, t.substr(1), output);
		int c = lcs_mem(s.substr(1), t.substr(1), output);
		ans = max(a, max(b, c));
	}

	// Save your calculation
	output[m][n] = ans;

	// Return ans
	return ans;
}
int lcs_mem(string s, string t) {
	int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}

	return lcs_mem(s, t, output);
}
//using dp
int lcs_dp(string s1,string s2)
{
	int m=s1.length();
	int n=s2.length();
	int **output = new int *[m+1];
	for(int i=0;i<= m;i++)
	{
		output[i] = new int[n+1];
	}
	//fill zeros in the first row, coz if length of s1=0 , then lcs=0;
	for(int i=0;i<=n;i++)
		output[0][i]=0;
	//similary fill first column with zero
	for(int i=0;i<=m;i++)
		output[i][0]=0;
	//start filling the row downwards
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s1[m-i]==s2[n-j])
				{
					output[i][j] = 1+output[i-1][j-1];
				}
			else
			{
				int ans= max(output[i-1][j],max(output[i][j-1],output[i-1][j-1]));
				output[i][j]=ans;
			}
		}
	}
	return output[m][n];
}
int main()
{
    string s1;
    string s2;
    cout<<endl<<"enter both strings separated by space - ";
    cin>>s1>>s2;
	 cout<<endl<<"lcs using dp = "<<lcs_dp(s1,s2)<<endl;
    cout<<endl<<"lcs using memoization = "<<lcs_mem(s1,s2)<<endl;
    cout<<endl<<"lcs = "<<lcs(s1,s2)<<endl;
    
}