#include "day3_a.h"

CustomerCar::CustomerCar(std::string registration_number){
    this->registration_number = registration_number;
}


void ServiceShop::register_car(CustomerCar *car){
    this->cars.add(car);
    std::cout << car->registration_number << " added, yay!" << std::endl;
}

CustomerCar *ServiceShop::find_car(std::string registration_number){
    return this->cars.find(registration_number);
}

void ServiceShop::remove_car(std::string registration){
    this->cars.remove(registration);
} 




main(){
    // create shop
    ServiceShop *shop = new ServiceShop();

    // create car with a reg number
    CustomerCar *new_car = new CustomerCar("JOL648");

    // add car to servide shop registry
    shop->register_car(new_car);
    // Add more cars
    new_car = new CustomerCar("HTF935");
    shop->register_car(new_car);

    // Find JOL648 
    CustomerCar *car = shop->find_car("JOL648");

    // define what type of part to change
    Windshield *new_windshield = new Windshield();
    Bumper *new_bumper = new Bumper();
   
    Service *new_service = new Service();
    new_service->change_part(new_windshield);
    new_service->change_part(new_bumper);
    new_service->set_payment(500, "cash");
    new_car->perform_service(new_service);


    new_service = new Service();
    new_service->change_part(new_windshield);
    new_service->change_part(new_bumper);
    new_service->set_payment(600, "credit");
    car->perform_service(new_service);


    new_service = new Service();
    new_service->change_part(new_windshield);;
    new_service->set_payment(200, "credit");
    car->perform_service(new_service);


    new_car = new CustomerCar("OEN293");
    shop->register_car(new_car);

    // Print content
    shop->print_cars();


    // remove someting from JOL648
    std::cout << &car->service_history->service->change_parts->part << std::endl; 
    delete car->service_history->service->change_parts->part;

    //shop->remove_car("HTF935");

    std::cout << "\n\n\n";
    shop->print_cars();



    Bumper *b = new Bumper();    
    delete b;

    return 0;
}