/*
Gary has two string S and V. Now Gary wants to know the length 
of shortest subsequence in S such that it is not a subsequence in V.
*/
//using memoization
/*
int solveHelper(string a,string b,int siA,int siB,int**dp)
{
    // siA = start index of a
    if(siB == b.length())  // string b is empty
        return 1;
    if(siA == a.length())   //string a is empty, => no subsequence of is absent in b hence return a max value
        return 1001;
    if(dp[siA][siB] != -1)
        return dp[siA][siB];
    
    int option1 = solveHelper(a,b,siA+1,siB,dp); // s[siA] isn't included
    //search s[siA] in b
    int index = -1;
    for(int i=siB;i<b.length();i++)
        if(a[siA] == b[i])
            {
            index = i;
            break;
        }
    if(index == -1)   //=> s[siA] isn't in b
        return 1;
    //if s[siA] is in b
    int option2 = 1 + solveHelper(a,b,siA+1,index+1,dp);
    int ans = min(option1,option2);
    dp[siA][siB] = ans;
    return ans;
}
int solve(string S,string T)
{
    int m=S.length();
    int n=T.length();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=new int[m+1];
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    return solveHelper(S,T,0,0,dp);
}*/
//using dp
int solve(string S,string T)
{
    int m = S.length();
    int n = T.length(); 
  
    // declaring 2D array of m + 1 rows and 
    // n + 1 columns dynamically 
    int dp[m+1][n+1]; 
  
    // T string is empty 
    for (int i = 0; i <= m; i++) 
        dp[i][0] = 1; 
  
    // S string is empty 
    for (int i = 0; i <= n; i++) 
        dp[0][i] = 1001; //first string is empty , then there is no subsequence in S which is not in T because T will always have an empty Subsequence.
    						// hence we return a maximum value;
  
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            char ch = S[i-1]; 
            int k; 
            for (k = j-1; k >= 0; k--) //search if k exists in T , if not smallest subsequence length here is 1.
                if (T[k] == ch) 
                    break; 
  
            // char not present in T 
            if (k == -1) 
                dp[i][j] = 1; 
            else           //excluding k  // including k
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1); 
        } 
    } 
  
    int ans = dp[m][n];
  
    return ans; 
}
int main()
{
	string S,V;
	cin>>S>>V;
	cout<<solve(S,V)<<endl;
	return 0;
}