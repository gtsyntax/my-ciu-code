struct ListNode{
    int data;
    ListNode* next;

    ListNode(int data){
        data = data;
        next = NULL;
    }
};

class LinkedList{
    ListNode* head;
    int list_size;
    
    public:
        LinkedList();
        ~LinkedList();
        int size();
        bool empty();
        int value_at(int index);
        void push_front(int value);
        int pop_front();
        void push_back(int value);
        int pop_back();
        int front();
        int back();
        void insert(int index, int value);
        void erase(int index);
        int value_n_from_end(int n);
        void reverse();
        void remove_value(int value);
};
