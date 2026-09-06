class Solution {
public:

    class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Har list ka first node heap mein daalo
        for (ListNode* list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Heap se smallest node nikalte raho
        while (!pq.empty()) {

            ListNode* smallest = pq.top();
            pq.pop();

            // Result list mein add
            tail->next = smallest;
            tail = tail->next;

            // Same list ka next node heap mein daalo
            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};