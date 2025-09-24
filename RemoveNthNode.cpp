#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for(int i = 0; i < n + 1; i++){
            fast = fast->next;
        }
        slow->next;
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
        }
    cout << endl;
}

int main()
{
    //change remove value or add more values in ListOne
    int remove = 2;
    vector<int> ListOne = {1,2,3,4,5};
    ListNode* l1 = buildList(ListOne);

    Solution sol;
    ListNode* newHead = sol.removeNthFromEnd(l1, remove);

    printList(newHead);
}