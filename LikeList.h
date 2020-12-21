#pragma once
#ifndef LABS_LIKELIST_H
#define LABS_LIKELIST_H

#include <string>

struct Element {
    int data;
    Element *next;
};

Element *new_element();

size_t calculate_list_size_from(Element *element);

Element *get_last(Element *element);

size_t calculate_size_of_satisfactory_results(Element *element, bool (*predic)(int));

size_t delete_all_elements_after_including(Element *element);

Element *put_element_at_end_of(Element *after, Element *what);

void save_list_from_element_to_file(std::string file_name, Element *element);

Element *random_gen(size_t amount);

Element *get_list_from_file(std::string file_name);


#endif //LABS_LIKELIST_H