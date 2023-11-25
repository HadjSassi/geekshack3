#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{   string s;
    cin>>s;
    string ss="chak";
    string sb = "chouka";
    string st="chakchouka";
    int sum = 0;
    string::size_type i = s.find(st);
    string::size_type j = s.find(sb);
    string::size_type k = s.find(ss);
    int occurrences = 0;
    std::string::size_type pos1 = 0;
   
    
    while ((pos1 = s.find(st, pos1 )) != string::npos) {
          sum++;
          pos1 +=st.length();
          s.erase(i, st.length());
    }
    std::string::size_type pos2 = 0;
     while ((pos2 = s.find(sb, pos2 )) != string::npos) {
          sum++;
          pos2 +=sb.length();
         
    }
    std::string::size_type pos3 = 0;
     while ((pos3 = s.find(ss, pos3 )) != string::npos) {
          sum++;
          pos3 +=ss.length();
          
    }
    
 
    cout<<sum<<endl;
   

    


    return 0;
}