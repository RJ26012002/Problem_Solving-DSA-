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
    ListNode* reverseK(ListNode* &head, int k ,int l){
        if(head==NULL){
            return NULL;

        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        int count=0;
        
        if(l>=k){
            while(count<k && curr!=NULL){
                nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
                count++;
            }
        }
         else{
            return head;
        }
        l=l-k;

        ListNode* rem = reverseK(curr,k,l);
        head->next=rem;
        return prev;
    
    }
    
   
    int leng(ListNode* &head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l=leng(head);
        cout<<"length is "<<l<<endl;
        if(l<k){
            return head;

        }
        ListNode* ans = reverseK(head,k,l);
        return ans;
    }
        
};