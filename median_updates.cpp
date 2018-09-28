#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
/* Head ends here */

void littlesort(int A[], int n){
        
        int i  = n-1;
        bool swapped;
        
        do{
            
            swapped = false;
            
            if(i > 0 && A[i] < A[i-1]){
                
                int temp  = A[i];
                A[i]      = A[i-1];
                A[i-1]    = temp;  
                swapped   = true;
            }
            
            i = i - 1;
            
        }while(swapped);
}
    
int binarysearch(int arr[], int n, int x){
        
        int l = 0;
        int r = n - 1;
        
        while(l <= r){
            
            int m = (l+r)/2;
            
            if(arr[m] < x)
                l = m + 1;
            else if (arr[m] > x)
                r = m - 1;
            else
                return m;
        }
        
        return -1;
}

void adjust(int arr[], int id, int size){
        
        size = size - 1;
        
        for(int i = id; i<size; i++)
            arr[i] = arr[i+1];
        
}

void check(double a){
    
    std::string str = std::to_string (a);
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    if(str.at(str.size()-1)=='.')str.erase(str.size()-1);
    cout<<str<<"\n";
    
}

void median(int arr[], int size){
    
    if(size % 2 != 0)
        cout << arr[size/2] << endl;
    else{
        //cout << arr[size/2] << " " << arr[size/2 + 1] << endl;
        double num = (arr[size/2])/2.0 + (arr[size/2 - 1])/2.0;
        check(num);
    }
}

int main(void){

//Helpers for input and output

	int n;
	cin >> n;
	
    int *arr = new int[n];
    int size = 0;
	char op;
    int x;
    
	for(int i = 0; i < n; i++){
        
		cin >> op >> x;
        
        if(op == 'a'){
            
            arr[size]   = x;
            ++size;
            littlesort(arr, size);
            
            median(arr, size);
                
        }else{
               
            int id = binarysearch(arr, size, x);
                
            if(id == -1)
                cout << "Wrong!" << endl;
            else{
                    
                adjust(arr, id, size);
                --size;
                
                if(size > 0)
                    median(arr, size);
                else
                    cout << "Wrong!" << endl;
            }
        }
    }
    
	return 0;
}
