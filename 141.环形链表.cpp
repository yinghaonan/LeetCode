//1.快慢指针法
//判断链表是否有环，最简单的一种方法就是快慢指针，慢指针每次走一步，快指针每次走两步，如果相遇，说明有环。
class Solution {
public:
	bool hasCycle(ListNode* head){
		if(head==nullptr) return false;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while(slow!=fast){
			if(fast==nullptr || fast->next==nullptr) return false;
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
	}
};

class Solution {
public:
	bool hasCycle(ListNode* head){
		if(head==nullptr) return false;
		ListNode* slow = head;
		ListNode* fast = head;
		if(fast->next == nullptr) return false;
		do{
			slow = slow->next;
			fast = fast->next->next;
			if(fast==nullptr || fast->next==nullptr) return false;
		}while(slow!=fast)
		return true;
	}
};

//2.存放到集合中
class Solution {
public:
	bool hasCycle(ListNode* head){
		unordered_set<ListNode*> set;
		while(head!=nullptr){
			if(set.count(head)) return true;
			set.insert(head);
			head = head->next;
		}
		return false;
	}
};

//3.逐个删除
class Solution {
public:
	bool hasCycle(ListNode* head){
		if(head==nullptr || head->next == nullptr) return false;
		if(head->next == head) return true;
		//获取下一个结点nextnode
		ListNode* nextnode = head->next;
		//让当前结点的指针指向自己，即删除此结点。
		//上一步已经保存了当前结点指针所指向的下一个结点，因此可以用保存的副本nextnode进行递归
		head->next = head;
		//递归，查看下一个结点
		return hasCycle(nextnode);
	}
};

//4.先反转再比较
//关于链表的反转，可以看432.剑指Offer-反转链表的3种方式
//如果有环，那么链表反转后原来的头结点和反转之后的头结点一定是同一个。
class Solution {
public:
	ListNode* reverseList(ListNode* head){
		ListNode* newhead = nullptr;
		while(head!=nullptr){
			ListNode* temp = head->next;
			head->next = newhead;
			newhead = head;
			head = temp;
		}
		return newhead;
	}

	bool hasCycle(ListNode* head){
		ListNode* rev = reverseList(head);
		if(head!=nullptr && head->next!=nullptr && rev == head){
			return true;
		}
		return false;
	}
};

class Solution {
public:
	bool hasCycle(ListNode* head){
		ListNode* pre = head;
		while(pre!=nullptr){
			if(pre.val==100001){
				return true;
			}else{
				pre.val=100001;
				pre = pre->next;
			}
		}
		return false;
	}
};

class Solution {
public:
	bool hasCycle(ListNode* head){
		if(head==nullptr || head->next==nullptr) return false;
		ListNode* pre=head, p=head->next;
		pre->next=nullptr;
		while(p->next!=nullptr){
			ListNode* temp = p->next;
			//让p指向pre，p->next是一个指针
			p->next = pre;
			pre = p;
			p = temp;
		}
		//p是新的头结点，head是原本的头结点，只要p==head，就表示有环存在。
		if(p==head){
			return true;
		}else{
			return false;
		}
	}
};