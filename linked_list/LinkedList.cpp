#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(){
    head = NULL;
    list_size = 0;
}

LinkedList::~LinkedList(){
}

int LinkedList::size(){
    return list_size;
}

bool LinkedList::empty(){
    return head == NULL;
}

int LinkedList::value_at(int index){
    if(index < 0 || index >= list_size){
        std::cerr << "Index out of bounds!" << std::endl;
        return -1;
    }

    ListNode* curr = head;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }

    return curr->data;
}

void LinkedList::push_front(int value){
    ListNode* tmp = new ListNode(value);
    tmp->next = head;
    head = tmp;
    list_size++;
}

int LinkedList::pop_front(){
    if(head == NULL){
        std::cerr << "List is empty!" << std::endl;
        return -1;
    }

    int tmp = head->data;
    head = head->next;
    list_size--;
    return tmp;
}

void LinkedList::push_back(int value){
    if(head == NULL){
        push_front(value);
        return;
    }

    ListNode* curr = head;
    ListNode* tmp = new ListNode(value);

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = tmp;
    list_size++;
}

int LinkedList::pop_back(){
    if(head == NULL) return -1;

    ListNode* curr = head;
    if(curr->next == NULL){
        int value = curr->data;
        delete curr;
        head = NULL;
        list_size--;
        return value;
    }

    while(curr->next->next != NULL){
        curr = curr->next;
    }
    int value = curr->next->data;
    delete curr->next;
    curr->next = NULL;
    list_size--;
    return value;
}

int LinkedList::front(){
    if(head == NULL){
        std::cerr << "List is empty!" << std::endl;
        return -1;
    }

    return head->data;
}

int LinkedList::back(){
    if(head == NULL){
        std::cerr << "List is empty!" << std::endl;
        return -1;
    }
    
    ListNode* curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    return curr->data;
}

void LinkedList::insert(int index, int value){
    if(index < 0 || index > list_size){
        std::cerr << "Index out of bounds!" << std::endl;
        return;
    }

    if(index == 0){
        push_front(value);
        return;
    }

    ListNode* curr = head;
    for(int i = 0; i < index - 1; i++){
        curr = curr->next;
    }

    ListNode* tmp = new ListNode(value);
    tmp->next = curr->next;
    curr->next = tmp;
    list_size++;
}

void LinkedList::erase(int index){
    if(index < 0 || index >= list_size){
        std::cerr << "Index out of bounds!" << std::endl;
        return;
    }

    if(index == 0){
        pop_front();
        return;
    }

    ListNode* curr = head;
    for(int i = 0; i < index - 1; i++){
        curr = curr->next;
    }
    
    ListNode* tmp = curr->next;
    curr->next = tmp->next;
    delete tmp;
    list_size--;
}

int LinkedList::value_n_from_end(int n){
    ListNode* main_ptr = head;
    ListNode* ref_ptr = head;

    for(int i = 0; i < n; i++){
        if(ref_ptr == NULL) return -1;
        ref_ptr = ref_ptr->next;
    } 

    while(ref_ptr != NULL){
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }

    return main_ptr->data;
}

void LinkedList::reverse(){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void LinkedList::remove_value(int value){
    if(head == NULL){
        std::cerr << "List is empty!" << std::endl;
        return;
    }

    if(head->data == value){
        pop_front();
        return;
    }

    ListNode* curr = head;
    while(curr->next != NULL && curr->next->data != value){
        curr = curr->next;
    }

    if(curr->next == NULL){
        std::cerr << "Value not found in the list!" << std::endl;
        return;
    }

    ListNode* tmp = curr->next;
    curr->next = tmp->next;
    delete tmp;
    list_size--;
}
