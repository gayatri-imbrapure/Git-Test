// for applying binary serch the function should be monotonic(i.e either in increasing or decreasing order )

// why mid=start+(end-start)/2 ? 
// To prevent from integet overflow error 
// because the max value of int is 2^31-1, if(start=2^31-1 and end=2^31-1) then simply doing (start+end) the sum will be out of integer range 
// thefore doing start+(end-start)/2 will make sure that the bigger number is subracted and the mid will in the integer range 




#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int key){
     int s=0;
     int e=n-1;
     int mid=s+(e-s)/2;

     while(s<=e){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            s=mid+1;
        } 
        else if(arr[mid]>key){
            e=mid-1;
        }
        mid=s+(e-s)/2;
     }
     return -1;
}

int main(){
    int even[6]={2,4,6,8,12,18};
    int odd[5]={3,8,11,14,16};

    int evenf=binarySearch(even,6,12);
    cout<<"The element 12 is present at index: "<<evenf<<endl;
    int oddf=binarySearch(odd,5,11);
    cout<<"The element 11 is present at index: "<<oddf<<endl;

    return 0;

}

