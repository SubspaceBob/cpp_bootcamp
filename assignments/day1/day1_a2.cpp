#include <iostream>


main(){
    std::cout << "Give a cipher key" <<  std::endl;
    int key;
    std::cin >> key;
    std::cout << key << std::endl;


    std::cout << "Give a text in CAPS" <<  std::endl;
    std::string text;
    std::cin >> text;
    std::cout << text << std::endl;

    for (char c : text){
        if (c-key < 'A'){
            std::cout << static_cast < char> (c - key + 'Z' - 'A' + 1);    
        } else{
            std::cout << static_cast < char> (c - key);
        } 

    } 
    std::cout << std::endl;

} 