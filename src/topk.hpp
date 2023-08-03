#ifndef topk_HPP
#define topk_HPP
#include "files.hpp"

using namespace std;

typedef struct{
  string word;
  int occurrences;
} WordInfo;


void printGlossary(unordered_map<string,WordInfo> glossary);

//void existentWord (string str, map<string, WordInfo> &glossary);

void returnWord(char c, int &n,  string &str, unordered_map<string,WordInfo> &glossary);

#endif
