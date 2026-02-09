#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* temp=head->next;
        ListNode* curr=head;
        while(temp!=NULL){
            if(curr->val!=temp->val){
                curr->next=temp;
                curr=curr->next;
                temp=temp->next;
                continue;
            }
            ListNode* del=temp;
            temp=temp->next;
            delete del;
            
        }
        curr->next=NULL;
        return head;
    }
};