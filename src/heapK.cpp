#include "files.hpp"

using namespace std;

void heapSize(int *K){

    int k;

    cout << "Tamanho Heap: "; 
    cin >> k;

    *K = k;
}

bool higherValue(const WordInfo& a, const WordInfo& b) {
        return a.occurrences > b.occurrences;
}

void insertK(int &K, unordered_map<string, WordInfo> glossary, priority_queue<int> &heap){

    heapSize(&K);

    //cout << " tam " << K;

    int aux = 0;

    for (const auto& entry : glossary) {

        if (aux >= K)  break;
        
        //const string& word = entry.first;
        const WordInfo& info = entry.second;

        heap.push(info.occurrences);

        aux++;
    }
    
    
}
    
void printHeap(priority_queue<int> &heap){

    std::priority_queue<int> aux = heap;

    cout << "\nPrint Heap:  \n";

    while (!aux.empty()){
        std::cout << aux.top() << " ";
        aux.pop();
        cout << "aaaaa";
    }
}

// int getLastElement(const std::priority_queue<int>& heap) {
//     std::priority_queue<int> tempHeap = heap; // Cria uma cópia temporária

//     while(tempHeap.size() > 1) {
//         tempHeap.pop(); // Descarta os elementos até restar apenas o último
//     }

//     return tempHeap.top(); // Retorna o último elemento restante
// }

int getLastElement(const std::priority_queue<int>& heap) {
    std::priority_queue<int> tempHeap = heap; // Cria uma cópia temporária

    int x;

    while(tempHeap.size() > 1) {
        tempHeap.pop(); // Descarta os elementos até restar apenas o último
    }

    x = tempHeap.top();

    cout << "\nX: " << x << endl;

    return x; // Retorna o último elemento restante
}

void printInAscendingOrder(priority_queue<int>& heap) {
    std::priority_queue<int> copyHeap = heap; // Cria uma cópia da priority_queue

    std::vector<int> elements;
    while (!copyHeap.empty()) {
        elements.push_back(copyHeap.top());
        copyHeap.pop();
    }

    for (int i = elements.size() - 1; i >= 0; i--) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}


// void finaleHash(int K, unordered_map<string, WordInfo> glossary, priority_queue<int> heap){

//     int position = 0; // Começando da primeira posição
//     int start_position = K; // Iniciar a impressão a partir da 5ª posição
//     int current, last;

//     for (auto it = glossary.begin(); it != glossary.end(); ++it) {
        
//         if (position >= start_position){

//             current = it->second.occurrences; //atual
//             last = getLastElement(heap); //último
            

//             if(higher(current, last)){ //se atual maior que ultimo 
//                 heap.pop();
//                 heap.push(current);
//             }

//         }
//         ++position;
//     }
// }

bool higher(int a, int b) {
        return a > b;
}

//  int position = 0; // Começando da primeira posição
//     int start_position = K; // Iniciar a impressão a partir da 5ª posição

//     for (auto it = glossary.begin(); it != glossary.end(); ++it) {
//         if (position >= start_position) {
//             std::cout << "Word: " << it->first << " | Occurrence: " << it->second.occurrences << std::endl;
//         }
//         ++position;
//     }