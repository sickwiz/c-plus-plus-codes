// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array
void merge(int input[],int start,int mid,int end)
{
    int lCount=mid-start+1;
    int rCount=end-mid;
    int lArray[lCount];
    int rArray[rCount];
    int i,j,k;
    for(i=0;i<lCount;i++ )
    {
        lArray[i]=input[start+i];
    }
     for(i=0;i<rCount;i++ )
    {
        rArray[i]=input[mid+1+i];
    }
    i=0;
    j=0;
    k=start;
    while(i<lCount && j<rCount)
    {
        if(lArray[i]<=rArray[j])
        {
            input[k++]=lArray[i++];
        }
        else
        {
             input[k++]=rArray[j++];
        }
    }
    while(i<lCount)
    {
        input[k++]=lArray[i++];
    }
     while(j<rCount)
    {
        input[k++]=rArray[j++];
    }

    
}
void mergeHelper(int input[],int start,int end)
{
    if(start>=end)
        return;
    int mid = (start+end)/2;
    mergeHelper(input,start,mid);
    mergeHelper(input,mid+1,end);
    merge(input,start,mid,end);
}
void intersection(int input1[], int input2[], int size1, int size2)
{
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    mergeHelper(input1,0,size1-1);
    mergeHelper(input2,0,size2-1);
    int i=0;
    int j=0;
    while(i<size1 &&j<size2)
    {
        if(input1[i]==input2[j])
        {
            cout<<input1[i++]<<endl;
            j++;
        }
        else if(input1[i]>input2[j])
        {
            j++;
        }
        else
            i++;
    }
}












