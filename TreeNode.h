#include <iostream>
using namespace std;
template <class T>
class TreeNode{
  public:
    TreeNode(){
      data = T();
      key = -1;
      left = NULL;
      right = NULL;
    }
    TreeNode(T* d, int k){
      data = d;
      key = k;
      left = NULL;
      right = NULL;
    }
    ~TreeNode(){
      delete left;
      delete right;
      delete data;
    }

    T* data;
    int key;
    TreeNode<T> *left;
    TreeNode<T> *right;
};
/*
TreeNode::TreeNode(){
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(int k){
  key = k;
  left = NULL;
  right = NULL;
}

TreeNode::~TreeNode(){
  // research this on our own
}
*/
