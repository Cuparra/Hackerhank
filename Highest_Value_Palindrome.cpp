string highestValuePalindrome(string s, int n, int k) {
    
    int vec[n/2];
    int count       = 0;
    int size        = n/2;
    
    // turn a string into a palindrome
    for(int i=0;i<size;i++){
        
        if(s[i] != s[n-i-1]){
            
            if(s[i] > s[n-i-1])
                s[n-i-1] = s[i];
            else
                s[i] = s[n-i-1];
            
            ++count;
            
            vec[i] = 1;
        
        }else
            vec[i] = 0;
    }
    
    if(count > k)
        return "-1";
    
    for(int i=0;i<size && (k - count > 0);i++){
        
        //cout << s << endl;
            
        if(s[i] != '9' && s[n-i-1] != '9'){
            
            if(vec[i] == 1){
                            
                s[i]        = '9';
                s[n-i-1]    = '9';
                ++count;
            
            }else if(k - count > 1){
                
                s[i]        = '9';
                s[n-i-1]    = '9';
                count       = count + 2;
            
            }
        }
    }
    
    if(k-count > 0 && s[size] != '9')
        s[size] = '9';
    
    return s; 
}
