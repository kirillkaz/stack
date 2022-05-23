#ifndef STACK_STACK_H
#define STACK_STACK_H

template<typename T>

class stack{

    class node{
    public:
        node(){
            prev = nullptr;
            next = nullptr;
        }

        node(T data){
            this->data = data;
            this->next = nullptr;
        }

        T data;
        node* next;
        node* prev;
    };


public:
    node* first;
    node* last;

    stack<T>(){
        first = nullptr;
        last = nullptr;
    }

    stack(T data){
        first = node(data);
        last = node(data);
        first->next = nullptr;
        last->next = nullptr;
        last->prev = first;
    }

    void push(T data){

        if (first == nullptr){
            first = new node(data);
            last = first;
            first->next = last;
            last->prev = first;
        }

        else{
            last->next = new node(data);
            last->next->prev = last;
            last = last->next;
            if(first->prev != nullptr) first->prev = nullptr;
        }
    }

    T pop(){
       if(first!=nullptr) {
           T returnData = last->data;

           if (first == last) {
               first = nullptr;
               last = nullptr;
               return returnData;
           }

           else {
               node *del = last;

               last = last->prev;
               last->next = nullptr;

               if (del == first) del = nullptr;
               else delete (del);

               return returnData;
           }
       }
       return T();
    }

    friend void operator<<(std::ostream& stream ,stack<T>* data){
        node* cur = data->first;
        stream << "[";
        while (cur != data->last){
            stream << cur->data<<", ";
            cur = cur->next;
        }
        stream << cur->data<<"]";
    }

};
#endif //STACK_STACK_H
