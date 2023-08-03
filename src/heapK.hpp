#ifndef heapK_HPP
#define heapK_HPP
#include "files.hpp"

using namespace std;

void heapSize(int *K);
//bool higherValue(const WordInfo& a, const WordInfo& b);
void insertK(int &K, unordered_map<string, WordInfo> glossary, priority_queue<int> &heap);
void printHeap(priority_queue<int> &heap);
int getLastElement(const std::priority_queue<int>& heap);
bool higher(int a, int b);


void printInAscendingOrder(priority_queue<int>& heap);

#endif
