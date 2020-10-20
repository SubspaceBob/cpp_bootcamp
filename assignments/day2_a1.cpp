#include <iostream>


main(){
    std::cout << "Give a number between 0 and 10" <<  std::endl;
    int input;
    std::cin >> input;
    std::cout << "Give a number for first dimension" <<  std::endl;
    int dim1;
    std::cin >> dim1;
    std::cout << "Give a number for second dimension" <<  std::endl;
    int dim2;
    std::cin >> dim2;
    std::cout << "Give a number for third dimension" <<  std::endl;
    int dim3;
    std::cin >> dim3;
    int ***a = new int **[dim1];

    std::cout << "[";
    for (size_t i = 0; i < dim1; i++){
        int **a2 = new int *[dim2]; 
        std::cout << "[";
        for (size_t j = 0; j < dim2; j++){
            int *a3 = new int[dim3];
            std::cout << "[";
            for (size_t k = 0; k < dim3; k++){
                int r_num = rand() % (input-1) + 1;
                std::cout << " " << r_num;
                *(a3+k) = r_num;
            }
            std::cout << "]" << std::endl; 
            *(a2+j) = a3;
        }
        std::cout << "]" << std::endl; 
        *(a+i) = a2;
    }
    std::cout << "]" << std::endl; 
}
