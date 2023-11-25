#include <iostream>
using namespace std;

int main() {
  
  // declaring string
  string sentence = "chak chak slata mechwiya chouka chouka ";
  // initialising no of words to 0
  int words = 0;
  // store length of string in lenOfSentence
  int lenOfSentence = sentence.size();

  // run for loop from i = 0 to i = lenOfSentence
  // to iterate through each character of the string
  for(int i = 0; i < lenOfSentence; i++)
  {
    // check if current character is a space
    if(sentence[i] == ' ')
    {
      // if it is a space, increment word count
      words++;
    }

  }
  // at the end of the for loop, no. of spaces have been
  // counted. Increment word count one more time to get
  // no. of words
  words = words + 1;

  cout << "No. of words = " << words << endl;

}
  