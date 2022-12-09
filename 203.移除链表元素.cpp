class Solution{
public:
	ListNode* removeElements(ListNode* head, int val){
		//终止条件
		if(head == nullptr){
			return head;
		}
		//调用原函数
		head->next = removeElements(head->next, val);
		//返回值
		return head->val == val ? head->next : head;
	}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode* dummyHead = new ListNode(0, head);
        struct ListNode* temp = dummyHead;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};





struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0),next(nullptr){};
	ListNode(int x): val(x), next(nullptr){};
	ListNode(int x, ListNode* next): val(x), next(next){};
};

class Solution{
public:
	ListNode* removeElements(ListNode* head, int val){
		struct ListNode* newhead = new ListNode(0,head);
		struct ListNode* temp = newhead;
		while(temp->next!=nullptr){
			if(temp->next->val == val){
				temp->next = temp->next->next;
			}else{
				temp=temp->next;
			}
		}
		return newhead->next;
	}
};




























