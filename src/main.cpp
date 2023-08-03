#include "files.hpp"

using namespace std;

int main (){
  int n, K = 0;
  
  ifstream file;
  unordered_map<string, WordInfo> glossary;
  priority_queue<int> heap;
  
  if (!file){
    cout << "Error opening file.\n";
  }

  file.open("data/entrada.txt", ios::in);

  char c = '\0';
  string str = "";
  while(file){
    c = file.get();
    returnWord(c, n, str, glossary);
  }

  printGlossary(glossary);

  

  file.close();
  insertK(K, glossary, heap);
  //finaleHash(K, glossary, heap);

  printHeap(heap);

  int h = 0;
  h = getLastElement(heap);

  cout << "H: " << h << endl;
  printInAscendingOrder(heap);

  return 0;
}
