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
      size_=1;
      set(0,val);
    }

    else if(tail_->last<10){
      
      tail_->last++;
      size_++;
      set(size_-1, val);
    }
    else{
      Item* newNode = new Item;
      newNode->prev=tail_;
      newNode->first=0;
      newNode->last=1;
      tail_->next=newNode;
      tail_=newNode;
      size_++;
      set(size_-1,val);
    }
    
  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    //tail_->val[tail_->last];
    
    tail_->last--;
    size_--;
    if (tail_->first==tail_->last){
      Item* temp=tail_;
      tail_=tail_->prev;
      if (tail_){
        tail_->next=nullptr;
      }
      else{
        head_=nullptr;
      }
      delete temp;
    }
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){

    if(empty()){
      head_=tail_=new Item;
      head_->last=10;
      head_->first=9;
      size_=1;
      set(0,val);
    }
    else if(head_->first>0){
      head_->first--;
      size_++;
      set(0,val);
    }
    else{
      Item* newfront = new Item;
      head_->prev = newfront;
      newfront->last=10;
      newfront->first=9;
      newfront->next=head_;
      head_=newfront;
      size_++;
      set(0,val);
    }

    
    
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    head_->first ++;
    size_--;
    if(head_->last==head_->first){
      Item* temp=head_;
      head_=head_->next;
      if(head_){
        head_->prev=nullptr;
      }
      else{
        tail_=nullptr;
      }
      delete temp;
    }

  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{

    return tail_->val[tail_->last-1];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{

    return head_->val[head_->first];
  }
//////////check if those are const////////////////////////////////////////////////////////////////////////////////////


 std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(size_<=loc){
      return nullptr;
    }
    Item* curr=head_;
    while (curr!=nullptr){
      size_t num = curr->last -curr->first;
      if (loc<num){

        size_t index = curr->first + loc;
        const std::string* temp = &(curr->val[index]);
   
        return const_cast<std::string*>(temp);
      }
      loc-=num;
      curr=curr->next;
    }
    return nullptr;
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
