#include <iostream>


main(){
    std::cout << "Give a number between 0 and 10" <<  std::endl;
    int input;
    std::cin >> input;
    std::cout << input << std::endl;
    int three_dim_array[8][9][11];
    for (int i=0; i<8; i++){
        std::cout << "[";
        for (int j=0; j<9; j++){
            std::cout << "[";
            for (int k=0; k<11; k++){
                int r_num = rand() % (input-1) + 1;
                std::cout << " " << r_num;
                three_dim_array[i][j][k] = r_num;
            }
            std::cout << "]" << std::endl;   
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
} 