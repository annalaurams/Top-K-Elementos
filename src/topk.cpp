#include "include.hpp"

using namespace std;

// adicionar stop words

void addStopWord(unordered_map<string, WordInfo> &glossaryStopWords, string &s){

  WordInfo newWord;
  newWord.occurrences = 1;

  if (s != ""){
    if (glossaryStopWords.find(s) != glossaryStopWords.end()){}
    
    else glossaryStopWords[s] = newWord;
  }

  s = "";
}

// verifica se alguma palavra do texto é stop word e a remove

void existentWord(unordered_map<string, WordInfo> &glossary, unordered_map<string, WordInfo> &glossaryStopWords){

  for (const auto& entry : glossaryStopWords) {
      const string& stopWord = entry.first;
      
      if (glossary.find(stopWord) != glossary.end()) 
        glossary.erase(stopWord);
  }
}

// guardar o nome dos textos de entrada

void manyFiles(vector<string> &filenames){

  string name;

  for(int i = 1; i<=FILES; i++){
        string start = "data/text";
        string end = ".txt";
        string num = to_string(i);
        string main = start + num;
        name = main + end;
        filenames.push_back(name); 
    }
}

// processa os textos de entrada

void fileReading(char c, string &str, unordered_map<string, WordInfo> &glossary){

  switch(c){
    
      case ' ':
        cases(str, glossary); break;

      case '\n':
        cases(str, glossary); break;

      case '.':
        cases(str, glossary); break;

      case '!':
        cases(str, glossary); break;

      case '?':
        cases(str, glossary); break;

      case ',':
        cases(str, glossary); break;

      case ':':
        cases(str, glossary); break;

      case ';':
        cases(str, glossary); break;
  
      case '[':
        cases(str, glossary); break;

      case ']':
        cases(str, glossary); break;

      case '(':
        cases(str, glossary); break;

      case ')':
        cases(str, glossary); break;

      case '"':
        cases(str, glossary); break;

      case '+':
        cases(str, glossary); break;

      case '/':
        cases(str, glossary); break;

      case '\x9D':
        break;

      default:
      if(str == "--" || str == "^" || str == " — " || str == " —" || str == "—" || str == "”" || str == "“" || str == "-”" || str == "——")
        str = "";

      if((c != '-') && (c != '"') && (c != '\xE2') && (c != '\x80') && (c != '\x9D') && (c != '\x9C') && (c != '\x94'))
        str+=tolower(c);

      break;
    }
}

// trata palavras acentuadas

string accentuation(const string &word){

  string result = word;
  int cont = 0;

  string acentos = "áàâãäéèêëíìîïóòôõöúùûüç"; 

  for (int i = 0; i < (int)result.length(); ++i){

    char c = result[i];
    int aux = acentos.find(c);

    if (aux) cont++;
  }

  return result;
}

// identifica as palavras e conta as ocorrências

void cases(string &str, unordered_map<string, WordInfo> &glossary){

  WordInfo newWord;
  newWord.occurrences = 1;
  
  string element;

  if(glossary.find(str) != glossary.end()) 
    glossary[str].occurrences++;

  else if (str != ""){
    element = accentuation(str);
    glossary[element] = newWord;
  }

  str = "";
}

// exclui possíveis strings vazia do glossário

void removeErro(unordered_map<string, WordInfo> &glossary){

  for (auto it = glossary.begin(); it != glossary.end();) {
        if (it->first.empty() || it->first == "-") {
            
            it = glossary.erase(it);
            it->second.occurrences;
            it = glossary.erase(it);

        } else {
            ++it;
        }
    }
}

// imprimi o glossário

void printGlossary(unordered_map<string,WordInfo> glossary){

  for(auto& [key, word] : glossary){
    cout << key << ": " << word.occurrences << endl;
  }
}

// insere k elementos no heap

void insertK( unordered_map<string, WordInfo> glossary, vector<WordInfo> &heap){

  removeErro(glossary);

  WordInfo info;
  int aux = 0;

  for (const auto& entry : glossary){

      if(aux >= K)  break;
      
      info.word = entry.first;
      info.occurrences = entry.second.occurrences;

      heap.push_back(info);

      aux++;
  }

  printHeap(heap);
  //heapSort(heap, lenght);
}

// organiza o heap em ordem crescente

void heapify(vector<WordInfo> &heap, int &lenght, int i){

  cout << "\nI: " << i << endl;
 
    int largest = i;
    int right = 2 * i + 2; // nó direito
    int left = 2 * i + 1; // nó esquedo

    lenght = heap.size();


    
    if (left < lenght && heap[left].occurrences < heap[largest].occurrences)
        largest = left;

    if (right < lenght && heap[right].occurrences < heap[largest].occurrences)
        largest = right;

    if (largest != i){
        swap(heap[i], heap[largest]);
        heapify(heap, lenght, largest);
    }

}
 
void heapSort(vector<WordInfo> &heap, int &lenght){

  lenght = heap.size();

    for (int i = (lenght - 1); i >= 0; i--)
        heapify(heap, lenght, i);

    for (int i = lenght- 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

// compara o restante dos elementos da hash com o heap

void finaleHash(const unordered_map<string, WordInfo> glossary, vector<WordInfo> &heap, int &lenght, int i){

    int position = 0;
    int start = K;
    
    auto it = glossary.begin(); 

    for (; it != glossary.end() && position < start + 1; ++it, ++position) {} // Começar a partir de K 

    for (; it != glossary.end(); ++it){

        int current = it->second.occurrences; 

         WordInfo info;

         info.word = it->first;
         info.occurrences = it->second.occurrences;

         //heapify(heap, lenght, i);

         if (current > heap[0].occurrences){



          heap[0] = info;
          heapify(heap, lenght, i);
        
        }
    
   // heapSort(heap, lenght);
}}

// imprimi o heap

void printHeap(vector<WordInfo> &heap){

  cout << "\n-------------- HEAP --------------\n\n";

  for (const WordInfo& info : heap) {
          std::cout << info.word << ": " << info.occurrences << std::endl;
      }
}
