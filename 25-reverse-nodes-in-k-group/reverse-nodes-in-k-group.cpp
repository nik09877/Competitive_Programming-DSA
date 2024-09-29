/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLen(ListNode* head){
        ListNode* slow,*fast;
        slow = fast = head;
        int len = 1;
        while(fast->next and fast->next->next){
            len+=2;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next)
            len++;
        return len;
    }
    ListNode* go(ListNode* head,int rem_len,int& k){
        if(!head or rem_len<k)
            return head;
        ListNode* cur,*pre,*nxt;
        cur = head;
        pre = NULL;
        for(int i=0;i<k;i++){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        head->next = go(cur,rem_len-k,k);
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or k==1)
            return head;
        
        int len = getLen(head);
        return go(head,len,k);

    }
};