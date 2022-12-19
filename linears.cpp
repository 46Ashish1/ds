
#include<iostream>
using namespace std;
int linearsearch(int arr[], int n, int data){
    for(int i =0; i<n; i++){
        if(arr[i]==data){
            return i;
        }
    }
    return -1;
}
int main(){
    int n, arr[n], data, res;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    cout<<"enter the elements of the array"<<endl;
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    cout<<"enter the number you want to search"<<endl;
    cin>>data;
    res = linearsearch(arr,n, data);
    if(res!=-1)
    cout<<"the data is found at index: "<<res;
    else  
    cout<<"data is not found in the list "<<endl;
    cout<<res;
    return 0;
}
