#ifndef topk_HPP
#define topk_HPP
#include "include.hpp"

using namespace std;

typedef struct{

  string word;
  int occurrences;

}WordInfo;

void addStopWord(unordered_map<string, WordInfo> &glossaryStopWords, string &s);
void existentWord(unordered_map<string, WordInfo> &glossary, unordered_map<string, WordInfo> &glossaryStopWords);

void manyFiles(vector<string> &filenames);
void printGlossary(unordered_map<string,WordInfo> glossary);
void fileReading(char c, string &str, unordered_map<string, WordInfo> &glossary);
void cases(string &str, unordered_map<string, WordInfo> &glossary);

string accentuation(const string &word);
void removeErro(unordered_map<string, WordInfo> &glossary);

void insertK( unordered_map<string, WordInfo> glossary, vector<WordInfo> &heap);
void printHeap(vector<WordInfo> &heap);

void heapify(vector<WordInfo> &heap, int &lenght, int i);
void finaleHash(const unordered_map<string, WordInfo> glossary, vector<WordInfo> &heap, int &length, int i);

#endif
