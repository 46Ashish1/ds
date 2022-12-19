#include<iostream>
using namespace std;
int main()
{
    int i, n, arr[n], num, first, last, middle;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter"<<n<< "Elements (in ascending order): ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter Element to be Search: "<<endl;
    cin>>num;
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"The number, "<<num<<" found at Position "<<middle+1<<endl;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"The number, "<<num<<" is not found in given Array"<<endl;
    return 0;
}
