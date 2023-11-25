#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string removeSpaces(string str) 
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 
 
int main()
{   string s;
    getline(cin,s);
   // s = removeSpaces(s);
    //cout<<s;
    string ss="chak";
    string sb ="chouka";
    string st="chakchouka";
    int sum = 0;
    string::size_type i = s.find(st);
    string::size_type j = s.find(sb);
    string::size_type k = s.find(ss);

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
          s.erase(j, sb.length());
    }
    std::string::size_type pos3 = 0;
     while ((pos3 = s.find(ss, pos3 )) != string::npos) {
          sum++;
          pos3 +=ss.length();
          s.erase(k, ss.length());
    }
    
    s = removeSpaces(s);
    
    std::string::size_type pos4 = 0;
    std::string::size_type pos5 = 0;
    std::string::size_type pos6 = 0;
  
    while ((pos5 = s.find(sb, pos5 )) != string::npos) {
         sum++;
          pos5 +=sb.length();
          s.erase(j, sb.length());
    }

     while ((pos6 = s.find(ss, pos6 )) != string::npos) {
          sum++;
          pos6 +=ss.length();
          s.erase(k, ss.length());
    }
   
    cout<<sum+1<<endl;

    return 0;
}
