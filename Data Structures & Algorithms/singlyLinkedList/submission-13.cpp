class ListNode{   
    public:
        int val;
        ListNode *next;
        ListNode(int val){
            this->val = val;
            this->next = nullptr;
        }
};

class LinkedList {
ListNode *head;
ListNode *tail;
std::vector<int> values;
public:
    LinkedList() {
        head = nullptr;
        tail = head;
    }

    int get(int index) {
         if(index >= values.size()) return -1;
        ListNode* node = head;
        for(int i = 0; i < index; i++)
            node = node->next;
        return node->val;
    }

    void insertHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
        if(tail == nullptr) tail = head;
        values.insert(values.begin() , val);

    }
    
    void insertTail(int val) {
        ListNode *node = new ListNode(val);
        if(tail == nullptr){
            head = node;
            tail = head;
            values.push_back(val);
        }else{
            tail->next = node;
            tail = tail->next;
            values.push_back(val);
        }
    }

    bool remove(int index) {
    if(index < 0 || index >= values.size()) return false; // bounds check

    values.erase(values.begin() + index); // remove from vector

    // Remove head
    if(index == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        if(head == nullptr) tail = nullptr; // list became empty
        return true;
    }

    // Remove middle or tail
    ListNode* node = head;
    for(int i = 0; i < index - 1; i++) {
        node = node->next;
    }

    if(node == nullptr || node->next == nullptr) return false;

    ListNode* temp = node->next;
    node->next = node->next->next;

    // Update tail if needed
    if(node->next == nullptr) tail = node;

    delete temp;
    return true;
}


    vector<int> getValues() {
        return values;
    }
};
