class Solution {
public:
    struct compare{

        bool  operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        priority_queue<ListNode* , vector<ListNode*> ,compare>p;

        for(auto node : lists){
            if(node) p.push(node);
        }

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(!p.empty()){
            ListNode* smallest = p.top();
            p.pop();

            tail->next = smallest;
            tail = tail->next;

           if(smallest->next) p.push(smallest->next);

        }

        return dummy.next;
    }
};
