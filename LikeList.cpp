#pragma once

#include "LikeList.h"
#include <exception>
#include <stdexcept>

template<typename T>
class LikeList {
private:
    Element<T> *first_element;
    Element<T> *last_element;
    size_t size;

public:
    LikeList(Element<T> *element) {
        last_element = (first_element = element);
        size++;
    }

    LikeList(T value) {
        Element<T> *element = new Element<T>(value);
        size++;
        last_element = (first_element = element);
    }

    LikeList() { // very bad thing that must be unimplemented or sth like this
        last_element = (first_element = nullptr);
    }

    ~LikeList() {
        Element<T> *now = first_element;
        Element<T> *next_now;
        while (now != nullptr) {
            next_now = now->next;
            delete now;
            size--;
            now = next_now;
        }
    }

    size_t get_size() { /// size variable can be cheated, so it can be 'unstable' (when add to end by changing pointer on next in last element)
        return size;
    }

    // it will set size of list to new, but is it expected for user (?)
    size_t calculate_size(){
        Element<T>* now = first_element;
        size_t calc_size = 0;
        while (now != nullptr){
            calc_size++;
            now = now->next;
        }
        size = calc_size;
        return calc_size;
    }

    /// in some situations it can return nullptr
    Element<T> *get_first_element() {
        return first_element;
    }

    /// in some situations it can return nullptr
    Element<T> *get_second_element() {
        return first_element->next;
    }

    /// in some situations it can return nullptr
    Element<T> *get_last_element() {
        return last_element;
    }


/// pointer on next_element in element will be lost, so user must delete that element, if it unused
    void add_as_first(Element<T> *element) {
        Element<T> *first_element = this->first_element;
        size++;
        first_element = element;
        element->next = first_element;
    }

    void add_to_end(Element<T> *element) throw (std::logic_error) {
        //can be cheated, why explained at get_size()
        if (last_element->next != nullptr){
            throw std::logic_error("you changed pointer in next element of list that is unexpected for program,\n"
                                   " you can fix it 'legally' by changing pointer on last element that know list to nullptr, or by calling extra_fix_by_deleting_intruders() or extra_fix_by_legalising_intruders()");
        }
        last_element->next = element;
        last_element = element;
        size++;
    }

    void add_to_end_by_value(T value) {
        Element<T> *element = new Element<T>(value);
        add_to_end(element);
    }

    void extra_fix_by_deleting_intruders(){
        Element<T> *now = last_element->next;
        Element<T> *next_now;
        while (now != nullptr) {
            next_now = now->next;
            delete now;
            now = next_now;
        }
    }

    void extra_fix_by_legalising_intruders(){
        Element<T> *now = last_element->next;
        while (now != nullptr) {
            size++;
            if (now->next == nullptr){
                last_element = now;
                break;
            }
            now = now->next;
        }
    }

    // delete from list unimplemented, need to be implemented?
};