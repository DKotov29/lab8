#include <iostream>
#include <fstream>
#include "LikeList.h"


bool predicate(int a) {
    if (a > 36576912) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Element *first = random_gen(5);
    calculate_list_size_from(first);
    std::cout << calculate_list_size_from(first) << std::endl;
    std::cout << delete_all_elements_after_including(first) << std::endl;


    Element* now = first;
    std::cout << "Elements: "<< now->data << " ";

    while(now->next != nullptr){
        now = now->next;
        std::cout << now->data << " ";
    }

    std::cout << std::endl;
    std::cout << "Amount of elements, greater than 36576912: " << calculate_size_of_satisfactory_results(first, &predicate);
    std::cout << "Pointer on last element: " << get_last(first) << std::endl;


    return 0;
}