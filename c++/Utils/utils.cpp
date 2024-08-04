#include "utils.h"

LListNode::LListNode(int v) {
    this->value = v;
    this->next = nullptr;
}

LListNode::LListNode(int v, int n) {
    this->value = v;
    this->next = new LListNode(n);
}

LListNode::LListNode(std::vector<int> vals) {
    this->value = vals[0];
    this->next = new LListNode({vals.begin()+1,vals.end()});
}

void LListNode::print() {
    std::cout << "[" << this->value;
    LListNode* nxt = this->next;
    while (nxt) {
        std::cout << "->" << nxt->value;
    }
    std::cout << "]";
}

DLListNode::DLListNode(int v) {
    this->value = v;
    this->next = nullptr;
    this->prev = nullptr;
}

DLListNode::DLListNode(int v, int n) {
    this->value = v;
    this->next = new DLListNode(n);
    this->prev = nullptr;
}

DLListNode::DLListNode(int v, std::vector<int> vals) {
    this->value = v;
    int n = vals[0];
    this->next = new DLListNode(n, {vals.begin()+1,vals.end()});
}

void DLListNode::print() {
    std::cout << "[" << this->value;
    DLListNode* nxt = this->next;
    while (nxt) {
        std::cout << "->" << nxt->value;
    }
    std::cout << "]";
}

void printVector_Chr(std::vector<char> v) {
    std::cout << "[" << *v.begin();
    
    for(int i=1; i<v.size();i++) {
        std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printVector_Int(std::vector<int> v) {
    std::cout << "[" << *v.begin();
    
    for(int i=1; i<v.size();i++) {
        std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printVector_Str(std::vector<char*> v) {
    std::cout << "[" << *v.begin();
    
    for(int i=1; i<v.size();i++) {
        std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printArray_Int(int* arr, int N) {
    std::cout << "[" << arr[0];
    
    for(int i=1; i<N;i++) {
        std::cout << "," << arr[i];
    }
    std::cout << "]";
}

void printArray_Chr(char* arr, int N) {
    std::cout << "[" << arr[0];
    
    for(int i=1; i<N;i++) {
        std::cout << "," << arr[i];
    }
    std::cout << "]";
}

void printMatrix_Int(int **matrix, int w, int h) {
    std::cout << "\t[\n";
    for (int row=0;row<h;row++) {
        for (int col=0;col<w;col++){
            if (!col) std::cout << "\t\t[" << matrix[row][col];
            else std::cout << "," << matrix[row][col];
        }
        std::cout << "]\n";
    }
    
    std::cout << "\t]\n";
}