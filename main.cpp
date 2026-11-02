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
   int test1[] = {4, 1, 3, 2, 5}; 
   bool bruteResult1 = hasDuplicateBruteForce(test1, 5);
   bool sortResult1 = hasDuplicateSortScan(test1, 5);
   if (bruteResult1 == false && sortResult1 == false) {
    cout << "Test 1: PASS" << endl;
}
else {
    cout << "Test 1: FAIL" << endl;
}
int test2[] = {7, 7, 1, 2, 3};
   bool bruteResult2 = hasDuplicateBruteForce(test2, 5);
   bool sortResult2 = hasDuplicateSortScan(test2, 5);
   if (bruteResult2 == true && sortResult2 == true) {
    cout << "Test 2: PASS" << endl;
   }
   else {
    cout << "Test 2: FAIL" << endl;
   }
   int test3[] = {1, 2, 3, 9, 9};
    bool bruteResult3 = hasDuplicateBruteForce(test3, 5);
    bool sortResult3 = hasDuplicateSortScan(test3, 5);
    if (bruteResult3 == true && sortResult3 == true) {
    cout << "Test 3: PASS" << endl;
    }
    else {
    cout << "Test 3: FAIL" << endl;
    }
    int test4[] = {5, 5, 5, 5, 5};
    bool bruteResult4 = hasDuplicateBruteForce(test4, 5);
    bool sortResult4 = hasDuplicateSortScan(test4, 5);
    if (bruteResult4 == true && sortResult4 == true) {
    cout << "Test 4: PASS" << endl;
    }
    else {
    cout << "Test 4: FAIL" << endl;
    }

  int sizes[] = {4000, 8000, 16000, 32000, 64000};
  double bruteTimes[5];
double sortTimes[5];
  for(int i=0;i<5;i++)
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
makearray(arr,size,j+1);//make an array of size n with random numbers
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
average_time_brute_force = total_time_brute_force / 5.0 / 1000000.0;
 average_time_sort_scan=total_time_sort_scan/5.0/1000000.0;
  cout<<"Average time taken by hasDuplicateBruteForce: "<<average_time_brute_force<<" ms"<<endl;
 cout<<"Average time taken by hasDuplicateSortScan: "<<average_time_sort_scan<<" ms"<<endl;
 double speedup = average_time_brute_force / average_time_sort_scan;
 cout<<"Speedup: "<<speedup<<endl;
 bruteTimes[i] = average_time_brute_force;
 sortTimes[i] = average_time_sort_scan;
}
for (int i = 1; i < 5; i++) {
    double bruteGrowth = bruteTimes[i] / bruteTimes[i - 1];
    double sortGrowth = sortTimes[i] / sortTimes[i - 1];
    cout << "From n = " << sizes[i - 1] << " to n = " << sizes[i] << endl;
    cout << "  hasDuplicateBruteForce growth: " << bruteGrowth << endl;
    cout << "  hasDuplicateSortScan growth: " << sortGrowth << endl;
}
}


