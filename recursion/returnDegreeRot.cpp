/*Given an integer array, which is sorted (in increasing order) and has been rotated 
by some number k in clockwise direction. Find and return the k.
SAMPLE INPUT
6
5 6 1 2 3 4
OUTPUT
2
*/
// arr - input array
// n - size of array

int FindSortedArrayRotation(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int rot=0;
    bool flag=false;
    int i=0;
    while(i<n)
    {
        if(arr[i]<=arr[i+1])
        {
            rot++;
            i++;
            continue;
        }
        else
        {
         rot++;
            flag=true;
            break;
        }
        
    }
    if(flag)
        return rot;
    else
        return 0;
}
