#include<iostream>
using namespace std;

void swapValue(int *input,int index1,int index2)
{
    int temp = input[index1];
    input[index1] = input[index2];
    input[index2] = temp;
}
void upHeapify(int *input,int index)
{
    if(index == 0)
        return;
    int parentIndex = (index-1)/2;
    if(input[index] > input[parentIndex])
    {
         swapValue(input,index,parentIndex);
        upHeapify(input,parentIndex);
    }
    else
        return;
    
}
void downHeapify(int *input,int index,int len)
{
    if(len == 0)
        return;
      int maxIndex = index;
        int lChild = (2*index)+1;
        int rChild = (2*index)+2;
        int maxValue = input[index];
        if(lChild <= len && rChild <= len)
        {
            if(input[lChild] > input[rChild])
            {
                maxIndex = lChild;
                maxValue = input[lChild];
            }
            else
            {
                maxIndex = rChild;
                maxValue = input[rChild];
            }
            
        }
        else if(lChild <= len && rChild >len)
        {
            maxIndex = lChild;
                maxValue = input[lChild]; 
        }
        else if(rChild <=len && lChild >len)
        {
            maxIndex = rChild;
                maxValue = input[rChild];
        }
        if(maxIndex != index)
        {
            if(maxValue > input[index])
            {
                swapValue(input,maxIndex,index);
            downHeapify(input,maxIndex,len);
            }
            else
                return;
        }
        else
            return;
}
void removeMin(int *input , int len)
{
    if(len == 0)
        return;
    swapValue(input,0,len);
    downHeapify(input,0,len-1);
}
void inplaceHeapSort(int *input, int len)
{
    if(len == 0 || len ==1)
        return;
    for(int i=1; i < len; i++)
    {
        int parentIndex = (i-1)/2;
        if(input[i] > input[parentIndex])
        {
            upHeapify(input,i);
        }
    }
    for(int i=0; i<len; i++)
    {
        removeMin(input,len-i-1);
    }
}
int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}