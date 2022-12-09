struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x), next(next){};
};

//哈希表
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> set;
        struct ListNode* tmp = new ListNode(0, head);
        struct ListNode* newhead = tmp;
        while(tmp->next != nullptr){
            if(set.count(tmp->next->val)){
                tmp->next = tmp->next->next;
            }else{
                set.insert(tmp->next->val);
                tmp = tmp->next;
            }
        }
        return newhead->next;
    }
};

//迭代
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* tmp = head;
        if(head==nullptr) return head;
        while(head->next != nullptr){
            if(head->val == head->next->val){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return tmp;
    }
};

//递归
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(head->next == nullptr){
            return head;
        }
        ListNode* newhead = deleteDuplicates(head->next);
        if(head->val == newhead->val){
            head->next = newhead->next;
            // head->next = head->next->next;
        }
        return head;
    }
};