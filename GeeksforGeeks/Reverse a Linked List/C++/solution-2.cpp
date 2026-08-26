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
	private:
	Node * revHead = nullptr;
	public:
	Node* reverseList(Node* head) {
		if (!head || !head -> next) {
			return head;
		}
		
		Node * newHead = reverseList(head -> next);
		head -> next -> next = head;
		head -> next = nullptr;
		
		return newHead;
	}
};
