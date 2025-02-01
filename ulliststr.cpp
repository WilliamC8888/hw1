#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>

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

// WRITE YOUR CODE HERE////////////////////////////////////////////////////////////////
  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){

    if(empty()){
      head_=tail_=new Item;
      head_->first=0;
      head_->last=1;
      head_->val[0]=val;
    }

    if(tail_->last!=10){
      set(tail_->last, val);
      tail_->last++;
    }
    else{
      Item* newNode = new Item;
      newNode->prev=tail_;
      tail_->next=newNode;
      tail_=newNode;
      set(tail_->first,val);
      tail_->last+=1;
    }
    size_++;
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    //tail_->val[tail_->last];
    tail_->last--;
    size_--;
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    if(head_->first==0){
      Item* newfront = new Item;
      head_->prev = newfront;
      newfront->next=head_;
      head_=newfront;
      head_->last=10;
      head_->first=9;
      set(head_->first,val);
    }
    else{
      head_->first--;
      set(head_->first,val);
    }
    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){



    size_--;
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{

    return get((tail_->last)-1);
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    return get(head_->first);
  }
//////////check if those are const////////////////////////////////////////////////////////////////////////////////////


 std::string* ULListStr::getValAtLoc(size_t loc) const{

 }


//////////////////////////////////////////////////////////////////////////////////

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
