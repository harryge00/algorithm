/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *gh = NULL, *gp = NULL, *lh = NULL, *lp = NULL, *p = head;
        while(p) {
            if(p->val < x) {
                if(!lh) {
                    lh = p;
                }
                if(lp) {
                    lp->next = p;
                }
                lp = p;
            } else {
                if(!gh) {
                    gh = p;
                }
                if(gp) {
                    gp->next = p;
                }
                gp = p;
            }
            p = p->next;
        }
        if(lh) {
            head = lh;
        }
        if(lp) lp->next = gh;
        return head;
    }
};