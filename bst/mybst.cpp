#include <iostream>

class BST {
    float m_data;
    BST *m_left, *m_right;
public:
    BST();
    BST(float value);

    BST* insert(BST *root, float val);
    void preorder(BST *root);
    void inorder(BST *root);
    void postorder(BST *root);
};

BST::BST(): m_data{0.f}, m_left{nullptr}, m_right{nullptr} {}
BST::BST(float value): m_data{value}, m_left{nullptr}, m_right{nullptr} {}

BST* BST::insert(BST *root, float value) {
    if (root == nullptr) {
        return new BST(value);
    }

    if (value < root->m_data) 
        root->m_left = insert(root->m_left, value);
    else
        root->m_right = insert(root->m_right, value);
    return root;
}

void BST::preorder(BST *root) {
    if (root == nullptr)
        return;
    std::cout << root->m_data << std::endl;
    preorder(root->m_left);
    preorder(root->m_right);
}

void BST::inorder(BST *root) {
    if (root == nullptr)
        return;
    inorder(root->m_left);
    std::cout << root->m_data << std::endl;
    inorder(root->m_right);
}

void BST::postorder(BST *root) {
    if (root == nullptr)
        return;
    postorder(root->m_left);
    postorder(root->m_right);
    std::cout << root->m_data << std::endl;
}

int main() {
    BST bst;
    BST *root = nullptr;

    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 70);
    bst.insert(root, 60);
    bst.insert(root, 80);

    std::cout << "inorder: "<< std::endl;
    bst.inorder(root); 
    std::cout << "preorder: " << std::endl;
    bst.preorder(root); 
    std::cout << "postorder: " << std::endl;
    bst.postorder(root); 

    return 0;
}
