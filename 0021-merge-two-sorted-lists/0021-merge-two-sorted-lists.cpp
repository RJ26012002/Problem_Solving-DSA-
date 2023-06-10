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
    void insertAttail(ListNode* &tail,int data){
        ListNode* temp = new ListNode(data);
        tail->next=temp;
        tail=temp;
    }

    ListNode* merge(ListNode* &head1 , ListNode* &head2,ListNode* &anshead,ListNode* &anstail){
        ListNode* temp1=head1;
        ListNode* temp2=head2;
        ListNode* ans= anshead;
        ListNode* anst=anstail;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val == temp2->val){
                insertAttail(anst,temp1->val);
                insertAttail(anst,temp2->val);
                // ans->next=new ListNode(temp2->val);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->val>temp2->val){
                // ans->next= new ListNode(temp2->val);.
                insertAttail(anst,temp2->val);

                temp2=temp2->next;
            }
            else{
                // ans->next=new ListNode(temp1->val);
                insertAttail(anst,temp1->val);
                temp1=temp1->next;
            }
        }
        while(temp1!=NULL){
            // ans->next=new ListNode(temp1->val);
            insertAttail(anst,temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            // ans->next=new ListNode(temp2->val);
            insertAttail(anst,temp2->val);
            temp2=temp2->next;
        }

        return anshead;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* ans= new ListNode(0);
        ListNode* anshead=ans;
        ListNode* anstail=ans;
        ListNode* head=merge(list1,list2,anshead,anstail);
        return head->next;



        
    }
};