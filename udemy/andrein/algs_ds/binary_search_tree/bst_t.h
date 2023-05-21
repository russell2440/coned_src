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
 * @brief   This file contains the class declaration that encapsulates a binary
 *          search tree algorithm.
 */



namespace rhs
{

  class bst_t
  {

  public:

    //==================
    // Public Methods
    //==================

    bst_t();

    void insert(int value);

    bool lookup(int value);

    bool remove(int value);

    void display();


  private:

    //==================
    // Private Methods
    //==================

    class node
    {

    private:
      node()
      {}


    public:

      int value_;
      node* left_;
      node* right_;

      node(int value)
      {
        left_ = nullptr;
        right_ = nullptr;
        value_ = value;
      }
    };

    
    /* inorder_traverse
    Until all nodes are traversed −
    Step 1 − Recursively traverse left subtree.
    Step 2 − Visit root node.
    Step 3 − Recursively traverse right subtree.
    */
    void inorder_traverse(node *n);
    
    /* preorder_traverse
    Until all nodes are traversed −
    Step 1 − Visit root node.
    Step 2 − Recursively traverse left subtree.
    Step 3 − Recursively traverse right subtree.
    */
    void preorder_traverse(node *n);

    /* postorder_traverse
    Until all nodes are traversed −
    Step 1 − Recursively traverse left subtree.
    Step 2 − Recursively traverse right subtree.
    Step 3 − Visit root node.
    */
    void postorder_traverse(node *n);

    // recursive insert method
    void insert_(node *cn, int value);


    //=======================
    // Private Data Members
    //=======================

    node *root_;
  };

}


