#include<iostream>
#include<algorithm>
#include<chrono>//this library is used to measure the time taken by the function to execute
#include<random>
using namespace std;
bool hasDuplicateBruteForce(int arr[], int size){
for (int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
        if(arr[i]==arr[j]){
            return true;
        }
    }
}
return false;
}


bool hasDuplicateSortScan(int arr[], int size){
    sort(arr,arr+size);//sort the array 
    for(int i=0;i<size-1;i++){
        if(arr[i]==arr[i+1]){
            return true;
        }
    }
    return false;
}
void makearray(int arr[],int n, int randomSeed){
    mt19937 rng(randomSeed);
    int num=1;
    for(int i=0;i<n;i++){
arr[i]=num;
num++;
    }


}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    auto start_1=chrono::high_resolution_clock::now();//start time
hasDuplicateBruteForce(arr, size);
auto end_1 = chrono::high_resolution_clock::now();//end time
auto duration_1 = chrono::duration_cast<chrono::nanoseconds>(end_1 - start_1);//calculate the duration
cout<<"Time taken by hasDuplicateBruteForce: "<<duration_1.count()<<" nanoseconds"<<endl;
auto start_2=chrono::high_resolution_clock::now();
hasDuplicateSortScan(arr, size);
auto end_2= chrono::high_resolution_clock::now();
auto duration_2= chrono ::duration_cast<chrono::nanoseconds>(end_2 - start_2);
cout<<"Time taken by hasDuplicateSortScan: "<<duration_2.count()<<" nanoseconds"<<endl;


    }

