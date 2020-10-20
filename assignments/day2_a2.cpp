#include <iostream>

struct linked_struct{
    int value;
    linked_struct *next = nullptr;
};

linked_struct *get_last_item(linked_struct *entry){
    // find last item
    linked_struct *current_item = entry;
    while (current_item->next != nullptr){
        current_item = current_item->next;
    }  
    return current_item;
} 

int main(){
    // create head 
    linked_struct *head;

    head = new linked_struct;
    head->value = 12;
    head->next = nullptr;

    while (true){
        std::cout << "Give command" <<  std::endl;
    
        std::string input;
        std::cin >> input;
        if (input == "stop"){
            
            // stop execution
            break;
        } else if (input == "add") {
            std::cout << "Give a number" <<  std::endl;
            
            // get input value
            int val;
            std::cin >> val;
            
            // create new item with value
            linked_struct *new_item = new linked_struct();
            new_item->value = val;   

            // point last item 'next' pointer to new item
            get_last_item(head)->next = new_item;

        } else if (input == "remove") {
            // TBD
        } else if (input == "print") {
            // TBD
        } else{
            std::cout << "what?? try again" <<  std::endl;
        } 
    }
} 