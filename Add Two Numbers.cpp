class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
        ListNode* h = new ListNode(-1);
        ListNode* k = h;
        while(l1 || l2){
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int a = n1 + n2 + x;
            x = a/10;
            k->next = new ListNode(a%10);
            k = k->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(x){
            k->next = new ListNode(x);
        }
        return h->next;
    }
};