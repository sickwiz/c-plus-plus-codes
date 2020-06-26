
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
void mergeSort(int input[], int size)
{
   mergeHelper(input,0,size-1);
}


