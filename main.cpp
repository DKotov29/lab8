#include <iostream>
#include "LikeList.cpp"

int main() {
    Element* first = new_element();
    first->data = 5;
    std::cout << first->data;
    return 0;
}

