#ifndef DAY3_A_H
#define DAY3_A_H
#include <iostream>
#include <memory>
class Payment{
public:
    //Payment();// = delete;
    Payment(int amount, std::string method):amount(amount),method(method){};
    int amount;
    std::string method;
}; 

class Part{
public:
   ~Part(){
       std::cout << "deleting part" << std::endl;
   }  
} ;
class Windshield:public Part{};
class Bumper:public Part{};

class LinkedParts{
public:
    Part *part;
    LinkedParts *next = nullptr;
    LinkedParts() = default;
    ~LinkedParts(){
        std::cout << "Deleting part" << this << std::endl;
        delete this->part;
    }   
};

class Service{
public:
    Service(){};
    ~Service(){
        LinkedParts *last_part = this->find_last();
        while (last_part!=nullptr){
            delete last_part;
            std::cout << "Part deleted" << std::endl;
            last_part = this->find_last();
        }
    };  
    LinkedParts *change_parts = nullptr;
    std::string date;
    Payment *payment;

    void change_part(Part *part){
        LinkedParts *new_link = new LinkedParts();
        if (this->change_parts == nullptr){
            this->change_parts = new_link;
        } else {
            this->find_last()->next = new_link;
        } 
    }

    void set_payment(int amount, std::string method){
        this->payment = new Payment(amount, method);
        std::cout <<  amount << " " << method << std::endl;
    } 

    void remove(Part *part){
        std::cout << "Searching for "<< &part << std::endl;
        LinkedParts *current_partlink = this->change_parts;

        // if first part
        if (current_partlink->part == part){
            LinkedParts *lpart_to_be_removed = current_partlink;
            this->change_parts = current_partlink->next;
            delete lpart_to_be_removed; 
        } else { 
            while(current_partlink->next != nullptr){
                if (current_partlink->next->part == part){
                    LinkedParts *lpart_to_be_removed = current_partlink;
                } 
            }
        } 
           
    } 
private:
    LinkedParts *find_last(){
        LinkedParts *current_item = this->change_parts;
        
        while (current_item->next != nullptr){
            current_item = current_item->next;
        }  
        return current_item;
    }
};

class ServiceHistory{
public:
    Service *service;
    ServiceHistory *next = nullptr;
    ServiceHistory() = default;
    ~ServiceHistory(){
        std::cout << "Deleting service" << std::endl;
        //ServiceHistory *last_service = this->find_last();
        //while (last_service!=nullptr){
        //    std::cout << "Deleting service" << std::endl;
         //   delete last_service;
        //    last_service = this->find_last();
        //}
        delete service;
        std::cout << "Service deleted!" << std::endl;
    };
private:
    ServiceHistory *find_last(){
        ServiceHistory *current_item = this->next;
        
        while (current_item->next != nullptr){
            current_item = current_item->next;
        }  
        return current_item;
    } 
};

class CustomerCar{
public:
    CustomerCar(std::string registration_number);
    CustomerCar() = default;
    ~CustomerCar(){
        std::cout << "Deleting car" << std::endl;
        ServiceHistory *last_service = this->find_last();
        while (last_service!=nullptr){
            delete last_service;
            last_service = this->find_last();
        }
        std::cout << "Car deleted!" << std::endl;
    };   
    ServiceHistory *service_history = nullptr;
    std::string registration_number;
    
    void perform_service(Service *new_service){
        ServiceHistory *new_link = new ServiceHistory();
        new_link->service = new_service;
        if (this->service_history == nullptr){
            this->service_history = new_link;
            std::cout << "First service performed!" << std::endl;
        } else {
            this->find_last()->next = new_link;
            std::cout << "Follow-up service performed!" << std::endl;
        }
        
        std::cout << new_link->service->payment->method << std::endl;
    }

private:
    ServiceHistory *find_last(){
        ServiceHistory *current_item = this->service_history;
        
        while (current_item->next != nullptr){
            current_item = current_item->next;
        }  
        return current_item;
    }
};



class LinkedElement{
public:
    CustomerCar *car;
    LinkedElement *next = nullptr;
    LinkedElement() = default;
    ~LinkedElement(){
        std::cout << "Deleting LinkedElement" << std::endl;
        delete this->car;
    }  
};

class Database{
private:
    LinkedElement *elements = nullptr;

    LinkedElement *find_last(){
        LinkedElement *current_item = this->elements;
        
        while (current_item->next != nullptr){
            current_item = current_item->next;
        }  
        return current_item;
    }
public:
    Database(){
        this->elements = nullptr;
    }

    void add(CustomerCar *car){
        LinkedElement *new_link = new LinkedElement();
        new_link->car = car;
        std::cout << car->registration_number << std::endl;
        if (this->elements == nullptr){
            // if no elements, then set element pointer to this link
            this->elements = new_link;
        } else{
            // else store new_link on last-next pointer
            find_last()->next = new_link;
        } 
    }

    void remove(std::string registration_number){
        std::cout << "Searching for "<< registration_number << std::endl;
        LinkedElement *current_carlink = this->elements;

        // if first car
        if (this->elements->car->registration_number == registration_number)
        {
            LinkedElement *car_to_be_removed = current_carlink;
            this->elements = current_carlink->next; // point element to next in line (link or nullptr)
            delete car_to_be_removed;
        } else{ 
            // if not first car, check next
            while (current_carlink->next != nullptr){
                if (current_carlink->next->car->registration_number == registration_number)
                {
                    std::cout << "Found it, sure you want it removed?!" << std::endl;
                    // point to next-next(either a LinkedElement or nullptr)
                    current_carlink->next = current_carlink->next->next;
                    LinkedElement *car_to_be_removed = current_carlink->next;
                    delete car_to_be_removed;
                } else
                {
                // Just act as if it was removed normally, it's weekend soon anyway...
                }
            }  
        } 
    }
    
    CustomerCar *find(std::string registration_number){
        std::cout << "Searching for "<< registration_number << " in the massive database, get some coffee!" << std::endl;
        LinkedElement *current_carlink = this->elements;
        while (current_carlink != nullptr){
            if (current_carlink->car->registration_number == registration_number)
           {
               std::cout << "Found it, yay! " << std::endl;
               return current_carlink->car;
           } else
           {
               // We have lost the car, blame the IT-guy...
           } 
        } 
    }

    void print_cars(){
        std::cout << "printing cars" << std::endl;
        LinkedElement *current_carlink = this->elements;
        while (current_carlink != nullptr){
            std::cout << "Found car " << current_carlink->car->registration_number << std::endl;
            std::cout << "  Service history: " << std::endl;
            ServiceHistory *current_servicelink = current_carlink->car->service_history;
            while(current_servicelink != nullptr){
                std::cout << "      payment: " << current_servicelink->service->payment->amount << std::endl;
                std::cout << "      parts: " << std::endl;
                LinkedParts *current_partlink = current_servicelink->service->change_parts;
                while(current_partlink != nullptr){
                     std::cout << "         " << current_servicelink->service->change_parts->part << std::endl;
               current_partlink = current_partlink->next;
               } 
            current_servicelink = current_servicelink->next;
            } 
        current_carlink = current_carlink->next;
        }  
    }
};


class ServiceShop {
public:
    ServiceShop() = default;
    void register_car(CustomerCar *car);
    void change_part(); // class type as argument??
    void print_cars(){this->cars.print_cars();}
    void remove_car(std::string registration_number);
    CustomerCar *find_car(std::string registration_number);
private:
    Database cars; 
};



#endif