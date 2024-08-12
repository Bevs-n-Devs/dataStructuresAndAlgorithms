#include "utils.h"
#include <climits>

LListNode::LListNode(int v) {
    this->value = v;
    this->next = nullptr;
}

LListNode::LListNode(int v, int n) {
    this->value = v;
    this->next = new LListNode(n);
}

LListNode::LListNode(std::vector<int> vals) {
    if (!vals.size()) {
        return;
    }
    
    if (vals.size() == 1) {
        this->value = vals[0];
        this->next = nullptr;
    } else {
        this->value = vals[0];
        this->next = new LListNode({vals.begin()+1,vals.end()});
    }
}

void LListNode::print() {
    std::cout << "[" << this->value;
    LListNode* nxt = this->next;
    while (nxt) {
        std::cout << "->" << nxt->value;
        nxt = nxt->next;
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
        nxt = nxt->next;
    }
    std::cout << "]";
}

void printVector_Chr(std::vector<char> v) {
    std::cout << "[";
    
    for(int i=0; i<v.size();i++) {
        if (!i) std::cout << v[i];
        else std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printVector_Int(std::vector<int> v) {
    std::cout << "[";
    
    for(int i=0; i<v.size();i++) {
        if (!i) std::cout << v[i];
        else std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printVector_Str(std::vector<char*> v) {
    std::cout << "[";
    
    for(int i=0; i<v.size();i++) {
        if (!i) std::cout << v[i];
        else std::cout << "," << v[i];
    }
    std::cout << "]";
}

void printArray_Int(int* arr, int N) {
    std::cout << "[";
    
    for(int i=0; i<N;i++) {
        if (!i) std::cout << arr[i];
        else std::cout << "," << arr[i];
    }
    std::cout << "]";
}

void printArray_Chr(char* arr, int N) {
    std::cout << "[";
    
    for(int i=0; i<N;i++) {
        if (!i) std::cout << arr[i];
        else std::cout << "," << arr[i];
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

void printMatrix_Vector_Int(std::vector<std::vector<int>> matrix) {
    std::cout << "\t[\n";
    for (int row=0;row<matrix.size();row++) {
        for (int col=0;col<matrix[0].size();col++){
            if (!col) std::cout << "\t\t[" << matrix[row][col];
            else std::cout << "," << matrix[row][col];
        }
        std::cout << "]\n";
    }
    
    std::cout << "\t]\n";
}