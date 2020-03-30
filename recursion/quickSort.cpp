int partition(int input[],int size)
{
    if(size==0 || size==1)
        return 0;
    int pivot=input[0];
    int pivotIndex=0;
    int temp;
    for(int i=1;i<size;i++)
    {
        if(input[i]<pivot)
            pivotIndex++;
    }
    if(pivotIndex>0)
    {
        temp=input[0];
        input[0]=input[pivotIndex];
        input[pivotIndex]=temp;
    }
    int i=0;   //left of pivot
    int j=pivotIndex+1;  //right of pivot
    while(i<pivotIndex && j<size)
    {
    if(input[i]>=pivot)
    {
        if(input[j]<pivot)
        {
            temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j++;
        }
        else
            j++;
    }
        else
            i++;
    }
    return pivotIndex;
}
void quickSort(int input[], int size)
{
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size==0 || size==1)
        return;
    int c=partition(input,size);
    //std::cout<<c<<"\n";
    quickSort(input,c+1);
    quickSort(input+c+1,size-c-1);
    
}

