
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

#include "bst_t.h"

#include <cstdio>

using namespace rhs;

//==============================================================================
//==============================================================================
bst_t::bst_t()
{
  root_ = nullptr;
}

//==============================================================================
//==============================================================================
void
bst_t::insert(int value)
{
  if (root_ == nullptr)
  {
    node *nn = new node(value);
    root_ = nn;
  }
  else
  {
    insert_(root_, value);
  }
  
  return;
}

//==============================================================================
//==============================================================================
bool
bst_t::lookup(int value)
{
  node *cn = root_;
  while(cn)
  {
    if(value < cn->value_)
    {
      cn = cn->left_;
    }
    else if(value > cn->value_)
    {
        cn = cn->right_;
    }
    else if(value == cn->value_)
    {
      return true;
    }
  }

  return false;
}

//==============================================================================
//==============================================================================
bool
bst_t::remove(int value)
{
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
  if(root_ == nullptr)
  {
    return false;
  } 

  node *cn = root_;
  node *pn = nullptr;
  while(cn)
  {
    if(value < cn->value_)
    {
      pn = cn;
      cn = cn->left_;
    }
    else if(value > cn->value_)
    {
      pn = cn;
      cn = cn->right_;
    }
    else if(value == cn->value_)
    {
      // we have a match, get to work.
      
      // Which node inherit's current nodes children? 
      // Why it's successor of course. 

      // option 1: no right child
      if (cn->right_ == nullptr)
      {
        // The current node is the root, and as there's 
        // no greater, no right child, the left child becomes
        // the new root.
        if (cn == root_)
        {
          root_ = cn->left_;
        }
        else
        {
          // Which way did we desend to 
          // this current node? We have 
          // only the parent to ask
          if (cn->value_ < pn->value_)
          {
            pn->left_ = cn->left_;
          }
          else if(cn->value_ > pn->value_)
          {
            pn->right_ = cn->left_;
          }
        }
      }
      else if (cn->right_->left_ == nullptr)
      // option 2: right child which doesn't have a left child.
      // Replace current node with right child.
      {
        // Connect current node left child to right child
        cn->right_->left_ = cn->left_;
        // Connect parent to right child
        if(cn == root_)
        {
          root_ = cn->right_;              
        }
        else
        {
          if(cn->value_ < pn->value_)
          {
            pn->left_ = cn->right_;
          }
          else
          {
            pn->right_ = cn->right_;
          }
        }

      }
      else
      // option 3: right child which has a left child
      {
        // Find replacement. Find right child's leftmost child.
        node *rnp = cn->right_;
        node *rn = rnp->left_;
        while(rn->left_)
        {
          rnp = rn;
          rn = rnp->left_;
        }

        // R's parent left child is now R's right child
        rnp->left_ = rn->right_;

        // Replace
        rn->left_ = cn->left_; 
        rn->right_ = cn->right_;
        
        if(cn == root_)
        {
          root_ = rn;
        }
        else
        {
          if(cn->value_ < pn->value_)
          {
            pn->left_ = rn;
          }
          else
          {
            pn->right_ = rn;
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

//==============================================================================
//==============================================================================
void
bst_t::display()
{
  inorder_traverse(root_);printf("\n");
  preorder_traverse(root_);printf("\n");
  postorder_traverse(root_);printf("\n");
}

//==============================================================================
//==============================================================================
/* inorder_traverse
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Visit root node.
Step 3 − Recursively traverse right subtree.
*/
void
bst_t::inorder_traverse(node *n)
{
  if (nullptr != n->left_)
  {
    inorder_traverse(n->left_);
  }

  printf("%d,",n->value_);

  if (nullptr != n->right_)
  {
    inorder_traverse(n->right_);
  }
}

//==============================================================================
//==============================================================================
/* preorder_traverse
Until all nodes are traversed −
Step 1 − Visit root node.
Step 2 − Recursively traverse left subtree.
Step 3 − Recursively traverse right subtree.
*/
void
bst_t::preorder_traverse(node *n)
{
  printf("%d,",n->value_);

  if (nullptr != n->left_)
  {
    preorder_traverse(n->left_);
  }

  if (nullptr != n->right_)
  {
    preorder_traverse(n->right_);
  }
}

//==============================================================================
//==============================================================================
/* postorder_traverse
Until all nodes are traversed −
Step 1 − Recursively traverse left subtree.
Step 2 − Recursively traverse right subtree.
Step 3 − Visit root node.
*/
void
bst_t::postorder_traverse(node *n)
{
  if (nullptr != n->left_)
  {
    postorder_traverse(n->left_);
  }

  if (nullptr != n->right_)
  {
    postorder_traverse(n->right_);
  }

  printf("%d,",n->value_);
}

//==============================================================================
//==============================================================================
// recursive insert method
void
bst_t::insert_(node *cn, int value)
{
  if (value<cn->value_)
  {
    if(cn->left_ == nullptr)
    {
      node *nn = new node(value);
      cn->left_ = nn;

      return;
    }

    insert_(cn->left_, value);
  }
  else 
  {
    if(cn->right_ == nullptr)
    {
      node *nn = new node(value);
      cn->right_ = nn;

      return;
    }

    insert_(cn->right_, value);
  }
}


