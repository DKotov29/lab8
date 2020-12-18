#pragma once
#ifndef LABS_LIKELIST_H
#define LABS_LIKELIST_H

struct Element {
    int data;
    Element *next;
};

Element *new_element();

size_t calculate_list_size_from(Element *element);

Element *get_last(Element *element);

size_t calculate_size_of_satisfactory_results(Element* element, bool (*predic)(int));

bool predicate(int a);

#endif //LABS_LIKELIST_H