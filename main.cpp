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
void makearray(int arr[],int size, int randomSeed){//this function is used to make an array of size n with random numbers
    mt19937 rng(randomSeed);//random number generator
    int num=1;
    for(int i=0;i<size;i++){
arr[i]=num;
num++;
    }
    shuffle(arr,arr+size,rng);


}
int main(){

  int sizes[]={4000, 8000, 16000, 32000};
  for(int i=0;i<4;i++)
{
 cout<<"----------------------------------------"<<endl;
int size=sizes[i];
cout<<"Size of the array: "<<size<<endl;
long long total_time_brute_force=0;
long long total_time_sort_scan=0;
double average_time_brute_force=0;
double average_time_sort_scan=0;
    for (int j=0;j<5;j++)
    {
    cout << "\nTrial " << j + 1 << endl;

int * arr=new int[size];  
makearray(arr,size,75);//make an array of size n with random numbers
auto start_1=chrono::high_resolution_clock::now();//start time
bool resulte1 = hasDuplicateBruteForce(arr, size);
auto end_1 = chrono::high_resolution_clock::now();//end time
auto duration_1 = chrono::duration_cast<chrono::nanoseconds>(end_1 - start_1);//calculate the duration
total_time_brute_force += duration_1.count();
cout<<" hasDuplicateBruteForce: "<<duration_1.count()<<" ns"<<endl;
auto start_2=chrono::high_resolution_clock::now();
bool resulte2 = hasDuplicateSortScan(arr, size);
auto end_2= chrono::high_resolution_clock::now();
auto duration_2= chrono ::duration_cast<chrono::nanoseconds>(end_2 - start_2);
total_time_sort_scan += duration_2.count();
cout<<" hasDuplicateSortScan: "<<duration_2.count()<<" ns"<<endl;
cout<<"Brute Force Result: "<<boolalpha<<resulte1<<endl;
cout<<"Sort and Scan Result: "<<boolalpha<<resulte2<<endl;
    delete[] arr;
    }
     average_time_brute_force=total_time_brute_force/5.0;
 average_time_sort_scan=total_time_sort_scan/5.0;
  cout<<"Average time taken by hasDuplicateBruteForce: "<<average_time_brute_force<<" ns"<<endl;
 cout<<"Average time taken by hasDuplicateSortScan: "<<average_time_sort_scan<<" ns"<<endl;
}
}


