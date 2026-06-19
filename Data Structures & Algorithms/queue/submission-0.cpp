class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        Node(int val){
            this->next = nullptr;
            this->prev = nullptr;
            this->val = val;
        }
};

class Deque {
private:
    Node* dummyhead;
    Node* dummytail;
public:
    Deque() {
        dummyhead = new Node(0);
        dummytail = new Node(0);
        dummyhead->next = dummytail;
        dummytail->prev = dummyhead;
    }

    bool isEmpty() {
        return dummyhead->next == dummytail;
    }

    void append(int value) {
        Node* temp = new Node(value);
        Node* previous = dummytail->prev;

        dummytail->prev = temp;
        temp->prev = previous;

        temp->next = dummytail;
        previous->next = temp;
        
    }

    void appendleft(int value) {
        Node* temp = new Node(value);
        Node* nextNode = dummyhead->next;

        temp->next = nextNode;
        temp->prev = dummyhead;
        
        nextNode->prev = temp;
        dummyhead->next = temp;
    }

    int pop() {
        if(isEmpty())
            return -1;
        Node* toDel = dummytail->prev;
        Node* previous = toDel->prev;
        previous->next = dummytail;
        dummytail->prev = previous;
        int value = toDel->val;
        delete toDel;
        return value;
    }

    int popleft() {
        if(isEmpty()) return -1;

        Node* toDel = dummyhead->next;
        Node* nextNode = toDel->next;
        nextNode->prev = dummyhead;
        dummyhead->next = nextNode;
        int val = toDel->val;
        delete toDel;
        return val;
    }
};
