#include <bits/stdc++.h>
using namespace std;
int getSubstringsCount(string str, string start, string end) {
   int substrings_count = 0, str_length = str.size(), start_length = start.size(), end_length = end.size();
   int start_matches_index[str_length] = {0}, end_matches_index[str_length] = {0};
   for (int i = 0; i < str_length; i++) {
      if (str.substr(i, start_length) == start) {
         start_matches_index[i] = 1;
      }
      if (str.substr(i, end_length) == end) {
         end_matches_index[i] = 1;
      }
   }
   set<string> substrings;
   string current_substring = "";
   for (int i = 0; i < str_length; i++) {
      if (start_matches_index[i]) {
         for (int j = i; j < str_length; j++) {
            if (!end_matches_index[j]) {
               current_substring += str[j];
            }
            if (end_matches_index[j]) {
               current_substring += str.substr(j, end_length);
               if (substrings.find(current_substring) == substrings.end()) {
                  substrings_count++;
               }
               substrings.insert(current_substring);
            }
         }
         current_substring = "";
      }
   }
   return substrings_count;
}
int main() {
   string str = "getmesomecoffee";
   string start = "m";
   string end = "e";
   cout << getSubstringsCount(str, start, end) << endl;
   return 0;
}   