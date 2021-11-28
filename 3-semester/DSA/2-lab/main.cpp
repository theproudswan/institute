#include <iostream>
#include <iomanip>
#include "search.h"

using namespace std;

const char consonants[] = "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
const char vowels[] = "AEIOUYaeiouy";

struct Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

void Insert(int _data, Node* &node){
    if(!node){
        node = new Node;
        node->data = _data;
        node->left = nullptr;
        node->right = nullptr;
        return;
    }
    if(_data < node->data){
        Insert(_data, node->left);
    }
    if(_data > node->data){
        Insert(_data, node->right);
    }
}


void Postorder(Node* node, int indent = 0){
    if(node) {
        if(node->right) {
            Postorder(node->right, indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (node->right) cout<<" /\n" << setw(indent) << ' ';
        cout<< node->data << "\n ";
        if(node->left) {
            cout << setw(indent) << ' ' <<" \\\n";
            Postorder(node->left, indent+4);
        }
    }
}

void Delete(Node* &node){
    if(node){
        if (node->left) Delete(node->left);
        if (node->right) Delete(node->right);
        delete node;
        node = nullptr;
    }
    return;
}

Node* Search (const int value, Node* node){
    if(!node) return nullptr;
    if(value < node->data) return Search(value, node->left);
    if(value > node->data) return Search(value, node->right);
    if(value == node->data) return node;
    return nullptr;
}

uint GetHeight(const Node* node){
    uint left, right, height = 0;
    if(node){
        left = GetHeight(node->left);
        right = GetHeight(node->right);
        height = max(left, right) + 1;
        // height = (left > right ? left : right) + 1;
    }
    return height;
}

uint NodeCount(Node* node){
    if (!node->left && !node->right) return 1;
    uint left, right;
    node->left ? left = NodeCount(node->left) : left = 0;
    node->right ? right = NodeCount(node->right) : right = 0;
    return left + right + 1;
}


Node* InOrderTravers(Node* root, const uint height) {
    static Node* found = nullptr;
    if (root){
        //cout << "Curr root is " << root->data << " and height is " << GetHeight(root) << endl;
        if (GetHeight(root) == height) {
            found = root;
            cout << 1 << endl;
            return found;
        }
        InOrderTravers(root->left, height);
        if (GetHeight(root) == height) {
            cout << 2 << endl;
            found = root;
            return found;
        }
        InOrderTravers(root->right, height);
        if (GetHeight(root) == height) {
            cout << 3 << endl;
            found = root;
            return found;
        }
        // return found;
    }
    return found;
}
Node* PreOrderTravers(Node* root, const uint height) {
    static Node* found = nullptr;
    if (root){
        //cout << "Curr root is " << root->data << " and height is " << GetHeight(root) << endl;
        if (GetHeight(root) == height) {
            found = root;
            cout << 1 << endl;
            return found;
        }
        PreOrderTravers(root->right, height);
        if (GetHeight(root) == height) {
            cout << 2 << endl;
            found = root;
            return found;
        }
        PreOrderTravers(root->left, height);
        if (GetHeight(root) == height) {
            cout << 3 << endl;
            found = root;
            return found;
        }
        // return found;
    }
    return found;
}


// Node* PreOrderTravers(Node* root) {
//     if (root){
//         return PreOrderTravers(root->right);
//         return PreOrderTravers(root->left);
//         return root;
//     }
//     return nullptr;
// }
// Node* InOrderTravers(Node* root) {
//     if (root){
//         return InOrderTravers(root->left);

//         // if (GetHeight(root) == height) {
//         //     cout << 2 << endl;
//         //     return root;
//         // }
//         return InOrderTravers(root->right);
//         // if (GetHeight(root) == height) {
//         //     cout << 3 << endl;
//         //     return root;
//         // }
//         return root;
//     }
//     return nullptr;
// }
// uint ConsonantCount(Node* node){
//     uint consonants = 0;
//     uint left = GetHeight(node->left);
//     uint right = GetHeight(node->right);
//     // cout << "left: " << left << endl
//     //      << "right: " << right << endl;
//     if(left == right){
//         cout << "Корень левого подузла: " << node->left->data << endl;
//         cout << "Корень правого подузла: " << node->right->data << endl;

//     } else {
//         if (right > left){
//             // cout << "Искомый height: " << left << endl;
//             Node* tmp = InOrderTravers(node->right, left);
//             // cout << "GetHeight(tmp): " << GetHeight(tmp) << endl;
//             if (GetHeight(tmp) == left){
//                 cout << "Корень левого подузла: " << node->left->data << endl;
//                 cout << "Корень правого подузла: " << tmp->data << endl;
//             }
//         } else {
//             // cout << "Искомый height: " << left << endl;
//             Node* tmp = PreOrderTravers(node->left, right);
//             // cout << "GetHeight(tmp): " << GetHeight(tmp) << endl;
//             if (GetHeight(tmp) == right){
//                 cout << "Корень левого подузла: " << tmp->data << endl;
//                 cout << "Корень правого подузла: " << node->right->data << endl;
//             }
//         }
//     }
//     if (min(left, right) > 1) {
//         if (left < right) {
//             ConsonantCount(node->right);
//         } else if (left > right) {
//             ConsonantCount(node->left);
//         } else {
//             cout << "Ёпта" << endl;
//         }
//     }
//     return consonants;
// }
uint VowelsAndConsonantsCount (Node* root){
    static uint vowels = 0;

    if (root){
        if (root->data % 2 == 0) vowels++;
        VowelsAndConsonantsCount(root->left);

        VowelsAndConsonantsCount(root->right);

    }
    //return nullptr;
    return vowels;
}


int main() {
    Node* root = nullptr;
    Insert(6, root);
    Insert(2, root);
    Insert(9, root);
    Insert(8, root);
    Insert(10, root);
    Insert(1, root);
    Insert(4, root);
    Insert(3, root);
    Insert(5, root);
    Insert(7, root);
    // Insert(9, root);
    // Insert(10, root);
    // Insert(11, root);
    // Insert(5, root);
    // Insert(4, root);
    // Insert(3, root);
    // Insert(2, root);
    // Insert(1, root);
    // Insert(0, root);




    cout << "Высота исходного дерева: " << GetHeight(root) << endl;
    int need_to_find = 2;
    cout << "Выполним поиск элемента " << need_to_find << ": " << Search(need_to_find, root);
    cout << endl << endl;
    cout << "Выведем дерево с помощью прямого обхода" << endl << endl;
    Postorder(root);
    cout << endl;
    cout << "Количество узлов: " << NodeCount(root) << endl;
    // ConsonantCount(root);
    cout << VowelsAndConsonantsCount(root) << endl;
    Delete(root);
    cout << endl << "Дерево удалено" << endl;
    cout << "Проверка. Высота дерева теперь: " << GetHeight(root) << endl;
    return 0;
}