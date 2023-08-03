#include "files.hpp"
#include <ctype.h>

using namespace std;

void printGlossary(unordered_map<string,WordInfo> glossary){
  for(auto& [key, word] : glossary){
    cout << key << ":" << word.occurrences << endl;
  }
}

void returnWord(char c, int &n, string &str, unordered_map<string, WordInfo> &glossary){
  WordInfo newWord;
  newWord.occurrences = 1;

  switch(c){
      case ' ':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '\n':
        n++;
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '.':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '!':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '?':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case ',':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case ':':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case ';':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '-':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '[':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case ']':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case '(':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      case ')':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
       case '"':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
       case '+':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
       case '/':
        if(glossary.find(str) != glossary.end()) glossary[str].occurrences++;
        else glossary[str] = newWord;
        str = "";
        break;
      default:
        str+= tolower(c);
        break;
    }
}
