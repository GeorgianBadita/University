
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = 0; i<v.size()/2; i++){
            if(v[i] != v[v.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};
