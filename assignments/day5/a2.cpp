#include <iostream>
#include <map>
#include <queue>

struct compare_by_value { 
    bool operator()(const std::pair<int,int> &a, const std::pair<int,int> &b) const {
        return a.second > b.second;
    } 
};

int main(){
    srand( (unsigned)time(NULL));
    std::priority_queue<int, std::vector<std::pair<int,int>>, compare_by_value> pq;

    // generate data
    int rand_nums[34] = {}; 
    for (int i = 0; i<10000; i++){
        int rand_num = rand() % 34;
        rand_nums[rand_num]+=1;
    } 

    // std::cout << "store data in proper container" << std::endl;
    // store data in proper container
    std::pair<int, int> *temp;
    for (int i = 0; i<34; i++){
        //std::cout << i << " - " << rand_nums[i]  << std::endl;
        auto temp = std::pair<int, int>(i, rand_nums[i]);
        pq.push(temp);
    } 

    // print data
    while (!pq.empty()){
        std::cout << pq.top().first << " - " << pq.top().second << std::endl;
        pq.pop();
    }

    return 0;
}