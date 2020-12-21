#include <cstdlib>
#include "LikeList.h"

#include <string>
#include <fstream>

Element *new_element() {
    Element *n = new Element;
    n->next = nullptr;
    return n;
}


Element *put_element_at_end_of(Element *after, Element *what) {
    get_last(after)->next = what;
    return what;
}

size_t calculate_list_size_from(Element *element) {
    size_t result = 0;
    Element *now = element;
    if (now != nullptr) result++;
    while (now->next != nullptr) {
        result++;
        now = now->next;
    }
    return result;
}

Element *get_last(Element *element) {
    Element *now = element;
    while (now->next != nullptr) {
        now = now->next;
    }
    return now;
}

Element *random_gen(size_t amount) { // always random gen at least 1
    Element *first = new_element();
    first->data = rand();
    size_t m = amount - 1;
    if (m > amount || m == 1) {
        return first;
    }

    Element *now = new_element();
    first->next = now;
    now->data = rand();
    m--;
    for (size_t i = 0; i < m; i++) {
        Element *new0 = new_element();
        now->next = new0;
        new0->data = rand();
        now = new0;
    }

    return first;
}

Element *get_list_from_file(std::string file_name) { // find from nowhere in some cases 2 elements
    std::ifstream in(file_name);
    Element *first = new_element(), *now = new_element();
    in >> first->data;
    first->next = now;
    while (!in.eof()) {
        in >> now->data;
        Element* new0 = new_element();
        now->next = new0;
        now = new0;
    }
    return first;
}

void save_list_from_element_to_file(std::string file_name, Element *element) {
    std::ofstream out(file_name);

    Element *now = element;
    out << now->data << ' ';
    while (now->next != nullptr) {
        now = now->next;
        out << now->data << ' ';
    }
}

size_t delete_all_elements_after_including(Element *element) {
    size_t res = 0;
    Element *now = element;
    while (now->next != nullptr) {
        Element *deleting = now->next;
        delete now;
        res++;
        now = deleting;
    }
    delete now;
    res++;
    return res;
}

size_t calculate_size_of_satisfactory_results(Element *element, bool (*predic)(int)) {
    size_t result = 0;
    Element *now = element;
    while (now->next != nullptr) {
        if (predic(now->data)) result++;
        now = now->next;
    }
    return result;
}

