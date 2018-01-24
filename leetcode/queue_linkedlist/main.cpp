// Implememt Queue using linked list

#include <iostream>
using namespace std;

struct Node{
    int value{-1};
    Node *next{nullptr};
    Node(int val) : value(val) {}
};

class MyQ{
    private:
        Node *m_head{nullptr};
        Node *m_tail{nullptr};
    public:
        void push(Node *node);
        Node *pop();
        void print();
};

void MyQ::push(Node *node){
    if(m_head == nullptr){
        m_head = node;
        m_tail = node;
        return;
    }

    m_tail->next = node;
    m_tail = node;    
}

Node * MyQ::pop(){
    if(m_head == nullptr){
        return nullptr;
    }

    Node *tmp = m_head;
    m_head = m_head->next;
    return tmp;
}

void MyQ::print(){
    Node *ptr = m_head;
    while(ptr){
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main(){
    MyQ my_q;
    my_q.push(new Node(1));
    my_q.push(new Node(2));
    my_q.push(new Node(3));
    my_q.push(new Node(4));
    my_q.push(new Node(5));
    my_q.pop();
    my_q.print();
    my_q.push(new Node(6));
    my_q.pop();
    my_q.print();

    return 0;
}

