#include <iostream>
#include "./shopping.h"

// Push Goods object to shopping_list_ vector
void Shopping::PushList(Goods object) {
  shopping_list_.push_back(object);
}

// Get Goods object from end of shopping_list_ vector
Goods Shopping::GetLastElement() {
  return shopping_list_.back();
}

// Print shopping_list_ Elements
void Shopping::PrintList() {
  for (std::vector<Goods>::iterator i = shopping_list_.begin();
      i != shopping_list_.end(); i++) {
    std::cout << "Goods #" << i->GetIndex() << " - Price : " <<
    i->GetPrice() << std::endl;
  }
}

// Sort shopping_list_ Elements by Price
// Apply Selection Sort algorithm
void Shopping::SortByPrice() {
  std::vector<Goods>::iterator min;
  for (std::vector<Goods>::iterator i = shopping_list_.begin();
      i != shopping_list_.end()-1; i++) {
    min = i;
    for (std::vector<Goods>::iterator j = i+1; j != shopping_list_.end(); j++) {
      if (min->GetPrice() > j->GetPrice()) {
        min = j;
      }
    }
    if(i != min)
      std::iter_swap(i, min);
  }
}

// Sort shopping_list_ Elements by Index
// Apply Selection Sort algorithm
void Shopping::SortByIndex() {
  std::vector<Goods>::iterator min;
  for (std::vector<Goods>::iterator i = shopping_list_.begin();
      i != shopping_list_.end()-1; i++) {
    for (std::vector<Goods>::iterator j = i; j != shopping_list_.end(); j++) {
      min = i;
      if (min->GetIndex() > j->GetIndex()) {
        min = j;
      }
    }
    if(i != min)
      std::iter_swap(i, min);
  }
}
