#include "utils.h"
#include <climits>


BinaryTreeNode::BinaryTreeNode() {
    
}

BinaryTreeNode::BinaryTreeNode(int v) {
    data = v;
    left = right = nullptr;
}

BinaryTree::BinaryTree(){
    this->root = new BinaryTreeNode();
}

BinaryTree::BinaryTree(int* arr, int N){
    root = new BinaryTreeNode(arr[0]);
    add_children_arr(root, arr, N);
}

BinaryTree::BinaryTree(std::vector<int> vec){
    if (!vec.size()) return;
    root = new BinaryTreeNode(vec[0]);
    add_children_vec(root, vec);
}

void BinaryTree::add_children_arr(BinaryTreeNode* node, int* arr, int N, int p){
    if (!N || p >= N) return;
    int l = p*2+1;
    int r = p*2+2;
    if (l < N && arr[l] != INT_MAX) node->left = new BinaryTreeNode(arr[l]);
    if (r < N && arr[r] != INT_MAX) node->right = new BinaryTreeNode(arr[r]);
    add_children_arr(node->left, arr, l, N);
    add_children_arr(node->right, arr, r, N);
}

void BinaryTree::add_children_vec(BinaryTreeNode* node, std::vector<int> vec, int p){
    if (!vec.size() || p >= vec.size()) return;
    
    int l = p*2+1;
    int r = p*2+2;

    if (l < vec.size() && vec[l] != INT_MAX) node->left = new BinaryTreeNode(vec[l]);
    if (r < vec.size() && vec[r] != INT_MAX) node->right = new BinaryTreeNode(vec[r]);
    add_children_vec(node->left, vec, l);
    add_children_vec(node->right, vec, r);
}

void BinaryTree::printTree(){
    if(!root) return;
    std::cout << "[ ";
    std::queue<BinaryTreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode* n = q.front();
        if (!n->data) {
            if (n == root) std::printf("null", n->data);
            else std::printf(", null", n->data);
        }
        else {
            if (n == root) std::printf("%d", n->data);
            else std::printf(", %d", n->data);
        }
        q.pop();
        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }
  
    std::cout << " ]";
}

// void BinaryTree::print(){BinaryTree::bfs(root);}

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

LList::LList(LListNode* node){
    head = node;
    
    if(head) size = 1;
    if (!head->next) {
        tail = head;
        return;
    }

    LListNode* nxt = this->head->next;
    while (nxt) {
        size++;
        if (!nxt->next) {
            tail = nxt;
            break;
        }
        nxt = nxt->next;
    }

}

void LList::printLLst(){
    std::cout << "[";
    LListNode* tmp = head;
    if (size == 1) {
        std::cout << tmp->value << "]";
        return;
    }
    while (tmp) {
        if (tmp == head) std::cout << tmp->value;
        else std::cout << "->" << tmp->value;
        
        tmp = tmp->next;
        if(tmp == tail) {
            std::cout << "->" << tmp->value;
            break;
        }
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

void printArray_Bytes(uint8_t* arr, int N) {
    std::cout << "[";
    
    for(int i=0; i<N;i++) {
        if (!i) std::cout << "0x" << std::hex << arr[i] + 0;
        else std::cout << ",0x" << std::hex << arr[i] + 0;
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
            if (!col) std::cout << "\t\t|" << matrix[row][col];
            else std::cout << "|" << matrix[row][col] << "|";
        }
        std::cout << "]\n";
    }
    
    std::cout << "\t]\n";
}

void printMatrix_Vector_Int(std::vector<std::vector<int>> matrix) {
    std::cout << "\t[\n";
    for (int row=0;row<matrix.size();row++) {
        for (int col=0;col<matrix[0].size();col++){
            int v = matrix[row][col];
            if (!col) if(v>9) std::cout << "\t\t|" << v; else std::cout << "\t\t| " << v;
            else if(v>9) std::cout << "|" << v; else std::cout << "| " << v;
        }
        std::cout << "|" << std::endl;
    }
    
    std::cout << "\t]\n";
}