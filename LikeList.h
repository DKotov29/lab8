#pragma once
#ifndef LABS_LIKELIST_H
#define LABS_LIKELIST_H

template<typename T>
struct Element {
    T value;
    Element *next;

    Element(T value) {
        this->value = value;
        this->next = nullptr;
    }

    Element* get_next(){
        return next;
    }



//    ~Element(){ todo need?
//
//    }
};


#endif //LABS_LIKELIST_H
