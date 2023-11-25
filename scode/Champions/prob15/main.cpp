#include <iostream>
 
using namespace std;
int plaindrome(string s)


    int freq[26];
 
    
    memset(freq, 0, sizeof freq);
 
    
    int count = 0;
 
    
    for (int i = 0; i < (int)s.length(); 
                                   ++i) {
        if (freq[s[i] - 'a'] == 0)
            count++;
 
        freq[S[i] - 'a']++;
    }
 
   
    int unique = 0;
    int duplicate = 0;
     
   
    for (int i = 0; i < 26; ++i) {
        if (freq[i] == 1)
            unique++;
        else if (freq[i] >= 2)
            duplicate++;
    }
 
    
    if (unique == 1 && 
     (unique + duplicate) == count)
        return 1;
 
    
    
}
int minInsertion(string s)
{
    
    int n = s.length();

    
    int res = 0;

    
    int count2[26] = { 0 };

    
    for (int i = 0; i < n; i++)
        count2[s[i] - 'a']++;

   
    for (int i = 0; i < 26; i++)
        if (count2[i] % 2 == 1)
            res++;

  
    return (res == 0) ? 0 : res - 1;
}

    
    int main(){
        string s;
        if( plaindrome(s)==1){
            cout<<minInsertion( s);
            
        }else{
            cout<<-1;
        }
        
        
        return 0;
    }

