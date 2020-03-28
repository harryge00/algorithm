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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	ListNode* kthHead = head;
    	ListNode* cur = head;
    	ListNode* next;
    	ListNode* lastEnd = new ListNode(0);
    	lastEnd->next = head;
    	ListNode* newHead = lastEnd;
    	while(cur) {
    		bool leftSmallerThanK = false;
    		next = cur->next;
    		// Check if the remaining list is shorter than K
    		for(int i = 1; i < k; i++) {
    			if(!next) {
    				leftSmallerThanK = true;
    				break;
    			}
    			next = next->next;
    		}
    		// If remaining shorter than K, just do nothing 
    		if(leftSmallerThanK) {
    			break;
    		}
    		kthHead = cur;
    		cur = cur->next;
    		for(int i = 1; i < k; i++) {
	        	next = cur->next;
	        	cur->next = kthHead;
	        	kthHead = cur;
	        	cur = next;
	        }
	        lastEnd->next->next = cur;
	        next = lastEnd->next;
	        lastEnd->next = kthHead;
	        lastEnd = next;
    	}
        return newHead->next;
    }
};