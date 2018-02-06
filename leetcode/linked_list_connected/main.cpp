 /*
 Given a lined list, and a list of nodes, find out the number of connected batches.

       +---+    +---+    +---+    +---+    +---+    +---+
        | 1 |--->| 2 |--->| 5 |--->| 4 |--->| 3 |--->| 7 |--->...
        +---+    +---+    +---+    +---+    +---+    +---+

(1, 4, 5) #2
(3,4,5,7) #1
*/



struct Node{
	int val;
	Node *next;
};

int count(Node *head, vector<Node *> list){
	if(head == nullptr){
		return 0;
}

	int cnt = 0
	unordered_map<Node*, int> mymap(list, 0);

	for(auto node : list){
		Node* next = node->next;
		if(mymap[next] != uordered_map<Node*, int>::iterator_end){
			++cnt;
		}
	}
	return cnt;
}


int main(){

	return 0;
}

(nullptr)
(3)
(1,2,3,5,4,7)
permutations
(2,1,3,4,5,7)

