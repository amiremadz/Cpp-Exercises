 /*
 Given a lined list, and a list of nodes, find out the number of connected batches.

        +---+    +---+    +---+    +---+    +---+    +---+
        | 1 |--->| 2 |--->| 5 |--->| 4 |--->| 3 |--->| 7 |--->...
        +---+    +---+    +---+    +---+    +---+    +---+

(1, 4, 5)    #2
(3, 4, 5, 7) #1
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node{
	int val{-1};
	Node *next{nullptr};
    Node(int value):val(value){}
};

int count(Node *head, vector<Node*> list){
	if(head == nullptr){
		return 0;
    }

	int cnt = 0;
	unordered_map<Node*, int> mymap;

    for(auto item:list){
        mymap.insert({item, 0});
    }

    for(auto node:list){
		Node* next = node->next;
        if(mymap.find(next) == mymap.end()){
            ++cnt;
		}
	}
	return cnt;
}

int main(){

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(5);
    Node *n4 = new Node(4);
    Node *n5 = new Node(3);
    Node *n6 = new Node(7);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    vector<Node*> sub1;
    vector<Node*> sub2 = {n1};
    vector<Node*> sub3 = {n2, n3, n4};
    vector<Node*> sub4 = {n3, n2, n4};
    vector<Node*> sub5 = {n1, n3, n4, n2};
    vector<Node*> sub6 = {n5, n3, n1};
    vector<Node*> sub7 = {n5, n3, n2, n1};

    cout << count(n1, sub1) << " - 0" << endl;
    cout << count(n1, sub2) << " - 1" << endl;
    cout << count(n1, sub3) << " - 1" << endl;
    cout << count(n1, sub4) << " - 1" <<endl;
    cout << count(n1, sub5) << " - 1" << endl;
    cout << count(n1, sub6) << " - 3"<< endl;
    cout << count(n1, sub7) << " - 2"<< endl;

    return 0;
}
