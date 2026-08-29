/* Structure of Linked List Node
class Node {
	public:
	int data ;
	Node *next ;
	
	Node(int x) {
		data = x ;
		next = nullptr ;
	}
};
*/

class Solution {
	public:
	Node* reverseList(Node* head) {
		if (!head || !head -> next)
			return head;
		
		Node * reverseHead = reverseList(head -> next);
		
		head -> next -> next = head;
		head -> next = nullptr;
		
		return reverseHead;
	}
};
