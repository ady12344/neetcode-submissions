class Node{
    public:
        int val;
        Node *next;
        Node(int val){
            this->val = val;
            this->next = nullptr;
        }
};


class LinkedList {
private:
    Node* head;
    Node* tail;    
public:
    
    LinkedList() {
        head = new Node(-1);
        tail = head;
    }

    int get(int index) {
        Node *curr = head->next;
        int i = 0;
        while(curr != nullptr){
            if(i == index){
                return curr->val;
            }
                
            i++;
            curr = curr->next;
        }    
        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head->next;
        head->next = node;
        if(node->next == nullptr)
            tail = node;
    }
    
    void insertTail(int val) {
        Node* node = new Node(val);
        tail->next = node;
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        Node *curr = head;
        while(i < index && curr !=nullptr){
            curr = curr->next;
            i++;
        }

        if(curr !=nullptr && curr->next != nullptr){
            if(curr->next == tail){
                tail = curr;
            }
            Node *del = curr->next;
            curr->next = curr->next->next;
            delete del;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        std::vector<int> vector;
        Node* curr = head->next;
        while(curr){
            vector.push_back(curr->val);
            curr = curr->next;
        }
            
        return vector;
    }
};
