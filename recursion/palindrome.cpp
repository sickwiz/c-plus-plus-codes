bool helper(char input[],int start,int end)
{
    if(start>=end)   //to include even length strungs
        return true;
    if(input[start]!=input[end])
        return false;
    else
        helper(input,start+1,end-1);
}
bool checkPalindrome(char input[]) {
    // Write your code here
    int len=0;
    while(input[len])
    {
        ++len;
    }
   // std::cout<<len;
   if(helper(input,0,len-1))
       return true;
    else
        return false;
}

