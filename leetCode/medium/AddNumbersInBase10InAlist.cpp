// /**
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          
          int val1 = l1->val;
          int val2 = l2->val;
          int thisResult = val1 +val2;
          bool toTheNext = false;
  
          if (thisResult >= 10) {
              thisResult -= 10;
              toTheNext = true;
          }
          ListNode* solution = new ListNode(thisResult);
          ListNode* it = solution;
          // First lets imagine the 2 list are same lengh
          while (l1->next != nullptr && l2->next != nullptr) {
              l1 = l1->next;
              l2 = l2->next;
              val1 = l1->val;
              val2 = l2->val;
  
              thisResult = val1+val2;
              thisResult = toTheNext ? thisResult + 1 : thisResult;
              toTheNext = false;
  
              if (thisResult >= 10) {
                  thisResult -= 10;
                  toTheNext = true;
              }
  
              ListNode* nextNode = new ListNode(thisResult);
              it->next = nextNode;
              it = it->next;
          }
  
          while (l2->next != nullptr) {
              l2 = l2->next;
              val2 = l2->val;;
  
              thisResult = val2;
              thisResult = toTheNext ? thisResult + 1 : thisResult;
              toTheNext = false;
  
              if (thisResult >= 10) {
                  thisResult -= 10;
                  toTheNext = true;
              }
  
              ListNode* nextNode = new ListNode(thisResult);
              it->next = nextNode;
              it = it->next;
          }
  
          while (l1->next != nullptr) {
              l1 = l1->next;
              val1 = l1->val;;
  
              thisResult = val1;
              thisResult = toTheNext ? thisResult + 1 : thisResult;
              toTheNext = false;
  
              if (thisResult >= 10) {
                  thisResult -= 10;
                  toTheNext = true;
              }
  
              ListNode* nextNode = new ListNode(thisResult);
              it->next = nextNode;
              it = it->next;
          }
  
          if (toTheNext) {
              ListNode* nextNode = new ListNode(1);
              it->next = nextNode;
              it = it->next; 
          }
  
  
  
          return solution;
  
      }
  };