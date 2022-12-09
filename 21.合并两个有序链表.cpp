//Definition for singly-linked list
struct ListNode{
	int val;
	ListNode* next;
	//以 成员初始化列表 的方式进行初始化
	ListNode(): int val(0), next(nullptr){};
	ListNode(int x): int val(x), next(nullptr){};
	ListNode(int x, ListNode* next): int val(x), next(next){};
};


//递归
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
		if(list1 == nullptr){
			return list2;
		}else if(list2 == nullptr){
			return list1;
		}else if(list1->val <= list2->val){
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}else{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
};

//递归
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
		if(list1 && list2){
			if(list1->val > list2->val){
				ListNode* temp = list2;
                list2 = list1;
                list1 = temp;
			}
			list1->next = mergeTwoLists(list1->next, list2);
		}
        if(list1==nullptr){
            return list2;
        }else{
            return list1;
        }
	}
};

//迭代
class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
		ListNode* head = new ListNode(-1);
		ListNode* prehead = head;
		while(list1!=nullptr && list2!=nullptr){
			if(list1->val <= list2->val){
				head->next = list1;
				list1 = list1->next;
			}else{
				head->next = list2;
				list2 = list2->next;
			}
			head = head->next;
		}
		if(list1==nullptr){
			head->next = list2;
		}else{
			head->next = list1;
		}
		return prehead->next;
	}
};