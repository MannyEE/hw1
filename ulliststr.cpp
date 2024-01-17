#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
    if (head_ == nullptr) {
        head_ = new Item;
        tail_ = head_;
        head_->val[0] = val;

        head_->first = 0;
        head_->last = 1;

        size_ = 1;
    } else if (tail_->last == ARRSIZE) {
        tail_->next = new Item;
        tail_->next->prev = tail_;
        tail_ = tail_ -> next;

        tail_->val[0] = val;

        tail_->first = 0;
        tail_->last = 1;

        size_++;
    } else {
        tail_->val[tail_->last] = val;
        tail_->last++;
        size_++;
    }
}

void ULListStr::pop_back(){
    if(empty()) return;

    tail_->last--;
    if (tail_->last == tail_->first) {
        if (head_ == tail_) {
            delete head_;
            head_ = tail_ = nullptr;
        } else if (head_ != tail_) {
            tail_ = tail_->prev;
            delete tail_->next;
            tail_->next = nullptr;
        }
    }

    size_--;
}

void ULListStr::push_front(const std::string& val) 
{
    if(empty()) {
        head_ = new Item;
        tail_ = head_;
        head_->val[ARRSIZE - 1] = val;

        head_->last = ARRSIZE;
        head_->first = ARRSIZE - 1;
        size_ = 1;

    } else if (head_->first == 0){
        head_->prev = new Item;
        head_->prev->next = head_;
        head_ = head_->prev;

        head_->last = ARRSIZE;
        head_->first = ARRSIZE - 1;
        head_->val[head_->first]=val;
        size_++;
    } else {
        size_++;
        head_->val[head_->first - 1] = val;
        head_->first--;
    }
}

void ULListStr::pop_front() 
{
    if(empty()) return;

    head_->first++;
    if (head_->first == head_->last) {
        if (head_ == tail_) {
            delete head_;
            head_ = tail_ = nullptr;
        } else {
            head_ = head_->next;
            delete head_->prev;
            head_->prev = nullptr;
        }
    }

    size_--;
}

std::string const & ULListStr::back() const
{
    return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
    if(loc > size_ - 1){
        return nullptr;
    } else {
        Item* curr = head_;
        int sum = curr->last - curr->first;

        while(sum <= loc) {
            curr = curr->next;
            sum += (curr->last - curr->first);
        }

        sum -= (curr->last - curr->first);

        // if (curr == head_) {
            return &(curr->val[curr->first + loc - sum]);
        // } else if (curr == tail_) {
        //     return &(curr->val[loc - sum]);
        // }else {
        //     return &(curr->val[loc - sum]);
        // }
    }
}

// ULListStr::~ULListStr(){
//     Item* curr = head_;
//     while(curr->next != nullptr) {
//         curr = curr->next;
//         delete curr->prev;
//     }

//     delete curr;
// }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
