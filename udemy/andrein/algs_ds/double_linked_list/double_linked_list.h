#include <iostream>
#include <vector>
using namespace std;

  // Create linked list with prepend and
  // append methods, using node class.
class double_linked_list{

  class node{
    public:
    int _value;
    node *_next;
    node *_prev;
    node(int value){
      _value = value;
      _next = nullptr;
      _prev = nullptr;
    }
  };

  node *_head = nullptr;
  node *_tail = nullptr;
  unsigned int _length = 0;
  
  void _init(int value){
    node *new_node = new node(value);
    _head = new_node;
    _tail = _head;
    _length = 1;
  };
  
  node *_traverse_to_index(unsigned int index){
    unsigned int i=0;
    node *cn = _head;
    while(i != index){
      cn = cn->_next;
      i++;
    }
    return cn;
  }
   public:

 //========================

  double_linked_list(){
  }
  
  double_linked_list(int value){
    _init(value);
  }
  
  void prepend(int value){
    node *new_node = new node(value);
    _head->_prev = new_node;
    new_node->_next = _head;
    _head = new_node;
    _length++;
  }

  void append(int value){
    // Initialization case
    if(!_length){
      _init(value);
      return;
    }
    // This node will be the new tail.
    // Point the old tail to this node, 
    // point the tail to this node.
    node *new_node = new node(value);
    _tail->_next = new_node;
    new_node->_prev = _tail;
    _tail = new_node;
    _length++;
  };

  void insert(unsigned int index, int value){
    // Traverse list to node indicated by index
    // Make new node, point to current node
    if(index==0){
      prepend(value);
      return;
    }
    if(index>=_length){
      append(value);
      return;
    }
    // create new node, traverse to leader,
    // patch in new node.
    node *leadn = _traverse_to_index(index-1);
    node *follown = leadn->_next;
    node *nn = new node(value);
    nn->_next = follown;
    nn->_prev = leadn;
    follown->_prev = nn;
    leadn->_next = nn;
    _length++;
  }

  void remove(unsigned int index){
    node *leadn = _traverse_to_index(index-1);
    node *rmn = leadn->_next;
    leadn->_next=rmn->_next;
    if(leadn->_next){
      leadn->_next->_prev = leadn;
    }
    _length--;
  }
  
  // Traverse ll and print each node value
  void print_rev(void){
    vector<int> val_array;
    node *cn = _tail;
    for(unsigned int i=0; cn!=nullptr; i++,cn=cn->_prev){
      val_array.push_back(cn->_value);
    }
    std::cout<<"R: ";
    for (std::vector<int>::iterator it = val_array.begin(); it != val_array.end(); it++){
      std::cout << *it << " ";
    }
    std::cout<<endl;
  
  }
  void print(void){
    vector<int> val_array;
    node *cn=_head;
    for(unsigned int i=0; cn != nullptr; i++,cn=cn->_next){
      val_array.push_back(cn->_value);
    }
    std::cout<<"F: ";
    for (std::vector<int>::iterator it = val_array.begin(); it != val_array.end(); it++){
      std::cout << *it << " ";
    }
    std::cout<<endl;
  }
};
