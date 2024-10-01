#include <iostream>

class MyVector{
    int arr_size = 0;
    int arr_capacity = 16;
    int* arr;
    
    void resize(int new_capacity){
        int* new_arr = new int[new_capacity];
        for (int i = 0; i < arr_size; i++){
            new_arr[i] = arr[i];
        }
        new_arr[arr_size] = item;
        delete[] arr;
        arr = new_arr; // Making the pointer to the old array point
        arr_capacity = new_capacity; // to the new array
    }

    public:
        MyVector(){
            arr = new int[arr_capacity];
        }
        
        ~MyVector(){
            delete[] arr;
        }
        
        int size(){
            return arr_size;
        }

        int capacity(){
            return arr_capacity;
        }

        bool is_empty(){
            return arr_size == 0;
        }

        int at(int index){
            if (index >= 0 && index < arr_size){
                return arr[index];
            } else {
                std::cerr << "Index out of bounds" << std::endl;
                return -1;
            }
        }

        void push(int item){
            if(arr_size == arr_capacity){
                resize(2 * arr_capacity);
            }
            arr[arr_size] = item;
            arr_size++;
        }

        void insert(int index, int item){
            if(index < 0 || index > arr_size){
                throw std::out_of_range("Index out of bounds");
            }

            if(arr_size == arr_capacity){
                resize(2 * arr_capacity);
            }

            for(int i = arr_size; i > index; i--){
                arr[i] = arr[i-1];
            }

            arr[index] = item;
            arr_size++;
        }

        void prepend(int item){
            insert(0, item);
        }

        int pop(){
            if(is_empty()){
                throw std::out_of_range("Cannot pop from an empty vector");
            }
            
            int popped_value =  arr[--arr_size];

            if(arr_size > 0 && arr_size == arr_capacity / 4){
                resize(arr_capacity / 2);
            }

            return popped_value;
        }

        void delete_at(int index){
            if(index < 0 || index > arr_size){
                throw std::out_of_range("Index out of bounds");
            }

            for(int i = index; i < arr_size - 1; i++){
                arr[i] = arr[i+1];
            }

            arr_size--; 

            if(arr_size > 0 && arr_size == arr_capacity / 4){
                resize(arr_capacity / 2);
            }
        }

        void remove(int item){
            int write_index = 0;
            
            for(int read_index = 0; read_index < arr_size; read_index++){
                if(arr[read_index] != item){
                    arr[write_index] = arr[read_index];
                    write_index++;
                }
            }

            arr_size = write_index;

            if(arr_size > 0 && arr_size == arr_capacity / 4){
                resize(arr_capacity / 2);
            }

        }

        int find(int item){
            for(int i = 0; i < arr_size; i++){
                if(arr[i] == item) return i;
            }
            return -1;
        }

};
