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
    // int LLtoInt(ListNode* &head){
    //     ListNode* temp=head;
    //     long long i=0;
    //     long long a =00;
    //     while(temp!=NULL){
    //         int data=temp->val;
    //         a+= data*pow(10,i);
    //         i++;
    //     }
    //     return a;
    // }
    // void insertAtHead(ListNode* &head , int d){
    //     ListNode* temp=new ListNode(d);
    //     temp->next=head;
    //     head=temp;
    // }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int a=LLtoInt(l1);
    //     int b=LLtoInt(l2);
    //     int c= a+b;
    //     int digit = c%10;
    //     c=c/10;
    //     ListNode* first= new ListNode(digit);
    //     ListNode* head=first;
    //     while(c!=0){
    //         int d=c%10;
    //         insertAtHead(head,d);
    //         c=c/10;
    //     }
    //     return head;
        
    // }
    // ListNode* reverse(ListNode* &head){
    //     ListNode* prev=NULL;
    //     ListNode* curr=head;
    //     ListNode* nxt=NULL;
    //     while(curr!=NULL){
    //         nxt=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=nxt;
    //     }
    //     return prev;
    // }
    // void insertAtTail(ListNode* &head, ListNode* &tail,int val){
    //     ListNode* temp = new ListNode(val);
    //     if(head==NULL){
    //         head=temp;
    //         tail=temp;
    //         return;

    //     }
    //     else{
    //         tail->next=temp;
    //         tail=temp;
    //     }
    // }
    // ListNode* add(ListNode* &first,ListNode* &second){
    //     int carry=0;
    //     ListNode* LLhead=NULL;
    //     ListNode* LLtail=NULL;
    //     while(first!=NULL && second!=NULL){
    //         int sum=carry + first->val + second->val;
    //         int digit=sum%10;
    //         insertAtTail(LLhead,LLtail,digit);
    //         carry=sum/10;
    //         first=first->next;
    //         second=second->next;
            
    //     }
    //     while(first!=NULL){
    //         int sum=carry+ first->val;
    //         int digit=sum%10;
    //         insertAtTail(LLhead,LLtail,digit);
    //         carry=sum/10;
    //         first=first->next;

    //     }
    //     while(second!=NULL){
    //         int sum=carry+ second->val;
    //         int digit=sum%10;
    //         insertAtTail(LLhead,LLtail,digit);
    //         carry=sum/10;
    //         second=second->next;

    //     }
    //     while(carry!=0){
    //         int sum=carry;
    //         int digit=sum%10;
    //         insertAtTail(LLhead,LLtail,digit);
    //         carry=sum/10;

    //     }
    //     return LLhead;
    // }
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    //     // revserse input ll
    //     ListNode* first=reverse(l1);
    //     ListNode* second=reverse(l2);

    //     // add two ll 
    //     ListNode* ans=add(first,second);
    //     return ans;

    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *p = l1, *q=l2, *curr = ans;
        int carry=0;
        while(p!=NULL || q!=NULL){
            int x = (p!=NULL) ? p->val : 0;
            int y = (q!=NULL) ? q->val : 0;
            int sum = carry + x+ y;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(p!=NULL) p = p->next;
            if(q!=NULL) q = q->next;
        }
        if(carry>0){
            curr->next = new ListNode(carry);
        }
        return ans->next;
    }
};