struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr){};
	ListNode(int x): val(x), next(nullptr){};
	ListNode(int x, ListNode* next): val(x), next(next){};
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pre = head;
        ListNode* p = head->next;
        pre->next = nullptr;
        while(p->next != nullptr){
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        p->next = pre;
        return p;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* pre = head;
        ListNode* p = head->next;
        //链表反转后，头结点变成尾结点，必须指向nullptr
        pre->next = nullptr;
        while(p != nullptr){
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        return pre;
    }
};

//递归
class Solution{
public:
	ListNode* reverseList(ListNode* head){
		if(head==nullptr || head->next==nullptr){
			return head;
		}
		ListNode* newhead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        //尾节点必须指向∅，否则会产生环
        //递归中每一步都使尾节点指向∅
        //下一次递归中，又是上一次递归的尾节点指向一个新的结点
        //直到最后一次递归结束时，最终的尾节点指向∅
        head->next = nullptr;
        return newHead;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) { return NULL; }
        ListNode* cur = head;
        while (head->next != NULL) {
            ListNode* t = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = t;
        }
        return cur;
    }
};

class Solution{
public:
	ListNode* reverseList(ListNode* head){
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* tmp = nullptr;
		while(cur!=nullptr){
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
};