bool checkAB(char input[]) {
	// Write your code here
    /*
    a. The string begins with an 'a'   
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
    */
       static int check=0;
    if(check==0)
    {
        if(input[check]!='a')
            return false;
        check++;
    }
    int len=0;
    while(input[len])
    {
        len++;
    }
    if(len==0)
        return true;
    if(input[0]=='a')
    {
        if(input[1]=='\0' || input[1]=='a')
           return 1 &  checkAB(input+1);
        else if(input[1]=='b' && input[2]=='b')
            return 1 & checkAB(input+1);
        else if(input[1]=='a')
            return 1 & checkAB(input+1);
        else
            return false;
    }
    if(input[0]=='b' && input[1]=='b')
    {
        if(input[2]=='a' || input[2]=='\0')
            return true & checkAB(input+1);
        else
            return false;
    }
    return 1 & checkAB(input+1);

}