#include "include.hpp"

using namespace std;

int main() {

    clock_t startTime, endTime;
    startTime = clock();

    unordered_map<string, WordInfo> glossary; 
    unordered_map<string, WordInfo> glossaryStopWords;
    vector<WordInfo> heap;
    vector<string> filenames;

    string s, filename;

    ifstream fileStopWords;
    fileStopWords.open("data/stopwords.txt", ios::in);

    while (fileStopWords){
        getline(fileStopWords, s, '\n');
        addStopWord(glossaryStopWords, s);
    }

    fileStopWords.close();

    manyFiles(filenames);
    
    for (string filename : filenames) {

        ifstream file;
        file.open(filename, ios::in);
        
        if (file.is_open()){

            char c = '\0';
            string str = "";

            while (file.get(c))
                fileReading(c, str, glossary); 
    
            file.close();
        } 
        else cout << "\nErro ao abrir o arquivo.\n";
    }

    existentWord(glossary, glossaryStopWords);

    int lenght = 0, i = 0;
    lenght = heap.size();

    insertK(glossary, heap);
    heapify(heap, lenght, 0);
    finaleHash(glossary, heap, lenght, i);
    printHeap(heap);
    
    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "\nTEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl;
    cout << endl;


    return 0;
}
