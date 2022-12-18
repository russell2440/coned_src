#pragma once

//==============================================================================
// (C) Copyright 2022, RHS Computing, LLC.
// All Rights Reserved
//
// NOTICE: The source code contained in this listing is a proprietary trade
//         secret of RHS Computing, LLC.  Unauthorized copying,
//         adaptation, distribution, use, or display is prohibited.
//==============================================================================

/** 
 * @file:   bst_t.h
 * @author: Russell Shahenian
 * @since:  12/18/22
 * @brief   This file contains the declaration of the bst_t class. 
 *          This is a class encapsulates a binary search tree algorithm.
 */



namespace rhs
{

  /**
   * An instance of the VMWInterface class is owned by a DataRouter object
   * to manage the need to send and receive packets over a UDP socket.
   *
   * The VMWInterface object receives packets from a single listening endpoint,
   * supplied at construction-time, and sends packets to one of two configured
   * destination endpoints.  The socket I/O is performed asynchronously using
   * a boost::asio::io_service object (owned by the DataRouter) that is supplied
   * to the VMWInterface object at the time of its construction.
   *
   * Packets received from the UDP socket are processed and delivered to the
   * DataRouter to be routed to other interface objects owned and managed by
   * the DataRouter.
   *
   * The DataRouter can ask the VMWInterface object to send MPLS Packets
   * or to send a "Pass-Through" packet. 
   */
  class bst_t
  {

public:
  bst(){
    _root = nullptr;
  }
  void insert(int value){
    if (nullptr == _root){
      node *nn = new node(value);
      _root = nn;
    } else {
      _insert(_root,value);
    }
    return;
    /*
    // create the node to be inserted
    // then find where to insert it
    node *nn = new node(value);
    if (nullptr == _root){
      _root = nn;
    } else {
      node *cn = _root;
      while(true){
        if (value < cn->_value){ //right
          if(nullptr == cn->_left){
            cn->_left = nn;
            break;
          }
          cn = cn->_left;
        } else { // right
          {
            if(nullptr == cn->_right){
              cn->_right = nn;
              break;
            }
            cn = cn->_right;
          }
        }
      }
    }
    */
  }
  bool lookup(int value){
      node *cn = _root;
      while(cn){
        if(value<cn->_value){
          cn = cn->_left;
        } else if(value>cn->_value) {
            cn = cn->_right;
        } else if(value==cn->_value) {
          return true;
        }
      }
      return false;
  }
  bool remove(int value){
    /*
    The general algorithm:
    - Search for v
    - If v is a leaf
        delete leaf v
    - Else If v has 1 child
        bypass v
    - Else 
        replace v with successor
    */ 
    if(!_root){
      return false;
    } 
    node *cn = _root;
    node *pn = nullptr;
    while(cn){
      if(value < cn->_value){
        pn = cn;
        cn = cn->_left;
      } else if(value > cn->_value){
        pn = cn;
        cn = cn->_right;
      } else if(value == cn->_value){
        // we have a match, get to work.
        
        // Which node inherit's current nodes children? 
        // Why it's successor of course. 

        // option 1: no right child
        if (!cn->_right) {
          // The current node is the root, and as there's 
          // no greater, no right child, the left child becomes
          // the new root.
          if (cn == _root) {
            _root = cn->_left;
          } else {
            // Which way did we desend to 
            // this current node? We have 
            // only the parent to ask
            if (cn->_value < pn->_value){
              pn->_left = cn->_left;
            } else if(cn->_value > pn->_value){
              pn->_right = cn->_left;
            }
          }

        // option 2: right child which doesn't have a left child.
        // Replace current node with right child.
        } else if (!cn->_right->_left) {
          // Connect current node left child to right child
          cn->_right->_left = cn->_left;
          // Connect parent to right child
          if(cn == _root){
            _root = cn->_right;              
          } else {
            if(cn->_value < pn->_value){
              pn->_left = cn->_right;
            } else {
              pn->_right = cn->_right;
            }
          }

        // option 3: right child which has a left child
        } else {
          // Find replacement. Find right child's leftmost child.
          node *rnp = cn->_right;
          node *rn = rnp->_left;
          while(rn->_left){
            rnp = rn;
            rn = rnp->_left;
          }
          // R's parent left child is now R's right child
          rnp->_left = rn->_right;
          // Replace
          rn->_left = cn->_left; 
          rn->_right = cn->_right;
          
          if(cn == _root){
            _root = rn;
          } else {
            if(cn->_value < pn->_value){
              pn->_left = rn;
            } else {
              pn->_right = rn;
            }            
          }
        }
        // Finally, delete current node.
        delete cn;

        return true;      
      } 
    }
    return false;
  }
  void display(){
    inorder_traverse(_root);printf("\n");
    preorder_traverse(_root);printf("\n");
    postorder_traverse(_root);printf("\n");
  }


  private:

    //==================
    // Private Methods
    //==================

    class node{
      node(){}
    public:
      int _value;
      node *_left;
      node *_right;
      node(int value){
        _left = nullptr;
        _right = nullptr;
        _value = value;
      }
    };

    node *_root;

    
    /* inorder_traverse
    Until all nodes are traversed −
    Step 1 − Recursively traverse left subtree.
    Step 2 − Visit root node.
    Step 3 − Recursively traverse right subtree.
    */
    void inorder_traverse(node *n){
      if (nullptr != n->_left){
        inorder_traverse(n->_left);
      }
      printf("%d,",n->_value);
      if (nullptr != n->_right){
        inorder_traverse(n->_right);
      }
    }
    
    /* preorder_traverse
    Until all nodes are traversed −
    Step 1 − Visit root node.
    Step 2 − Recursively traverse left subtree.
    Step 3 − Recursively traverse right subtree.
    */
    void preorder_traverse(node *n){
      printf("%d,",n->_value);
      if (nullptr != n->_left){
        preorder_traverse(n->_left);
      }
      if (nullptr != n->_right){
        preorder_traverse(n->_right);
      }
    }

    /* postorder_traverse
    Until all nodes are traversed −
    Step 1 − Recursively traverse left subtree.
    Step 2 − Recursively traverse right subtree.
    Step 3 − Visit root node.
    */
    void postorder_traverse(node *n){
      if (nullptr != n->_left){
        postorder_traverse(n->_left);
      }
      if (nullptr != n->_right){
        postorder_traverse(n->_right);
      }
      printf("%d,",n->_value);
    }

    // recursive insert method
    void _insert(node *cn, int value){
      if (value<cn->_value){
        if(!cn->_left){
          node *nn = new node(value);
          cn->_left = nn;
          return;
        }
        _insert(cn->_left,value);
      } else {
        if(!cn->_right){
          node *nn = new node(value);
          cn->_right = nn;
          return;
        }
        _insert(cn->_right,value);
      }
    }

    //=======================
    // Private Data Members
    //=======================
  };



int main() {
  printf("Binary Search Tree unit test, and Russell I LOVE you!\n");
  bst tree;
//                  9
//          4               20
//      1       6     15          170
//
  tree.insert(9);
  tree.insert(4);
  tree.insert(6);
  tree.insert(20);
  tree.insert(170);
  tree.insert(15);
  tree.insert(1);
  tree.display();

  int value = 20;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 25;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 254;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));
  value = 6;
  printf("Is %d in tree? %d\n",value, tree.lookup(value));

  tree.remove(6);
  tree.display();


  return 0;
}

