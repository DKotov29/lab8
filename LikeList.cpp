#include "LikeList.h"

Element *new_element() {
    Element *n = new Element;
    n->next = nullptr;
    return n;
}

Element *new_element_after(Element* after, Element* what) {
    after->next = what;
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

size_t calculate_size_of_satisfactory_results(Element *element, bool (*predic)(int)) {
    size_t result = 0;
    Element *now = element;
    while (now->next != nullptr) {
        if (predic(now->data)) result++;
        now = now->next;
    }
    return result;
}

bool predicate(int a) {
    if (a > 14) {
        return true;
    } else {
        return false;
    }
}