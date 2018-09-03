#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int q;
    int j = 0;
    string primal;
    stack<string> st;
    
    cin >> q;
    
    while(q--){
        
        int op;
        cin >> op;
        
        if(op == 1){
            
            string str;
            cin >> str;
            st.push(primal);
            primal += str;
            
        }else if(op == 2){
            
            int k;
            cin >> k;
            st.push(primal);
            primal.erase(primal.size()-k,k);
        
        }else if(op == 3){
            
            int k;
            cin >> k;
            cout << primal[k-1] <<endl;
            
        }else{
            
            primal = st.top();
            st.pop();
        
        }
        
        
    }
    
    return 0;
}
