#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;


bool AtListPosition (const string & word_list, const string & word, size_t i) {
  int sizeOfWord = static_cast<int>(word.length());
  if (word_list.substr(i, sizeOfWord) == word && ( i == 0|| !isalpha(word_list.at(i-1))
     ) && (i + word.size() == word_list.size() || !isalpha(word_list.at(i + word.size()) )) ){
    if (word_list.at(i) != word.at(0))
      return false;
    else
      return true;
  }
  return false;
  }

size_t FindInList (const string & wordList, const string & word, size_t i = 0) {
  for (;i < wordList.size(); i++) {
    if (AtListPosition(wordList, word, i))
      return i;
  }
    return string::npos;
}

string GetFirstInList (const string & wordList, string * word1, string * word2) {
  if (FindInList(wordList, *word1) < FindInList(wordList, *word2) )
    return *word1;
  if (FindInList(wordList, *word1) > FindInList(wordList, *word2) )
    return *word2;
  return "N/A";
  }

size_t CountInList (const string & wordList, const string & word) { 
  int sizeOfWordList = static_cast<int>(wordList.length());
  int count = 0;
  for (int i = 0; i < sizeOfWordList; i++) {
    if (AtListPosition(wordList, word, i))
      count += 1;
}
return count; }




int main()
{
  string word1, word2, wordList;
  string* p_word1 = &word1;
  string* p_word2 = &word2;
  cin >> word1;
  cin >> word2;
  while (cin >> wordList)
  cout << GetFirstInList(wordList, p_word1, p_word2) << " " <<
   CountInList(wordList, word1) << " " << CountInList(wordList, word2) << endl;
}
