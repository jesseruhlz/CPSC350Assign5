#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;
template <class T>
/*
class BST{
  private:
    TreeNode<T> *root;
    int size;
  public:
    BST();
    ~BST();

    bool searchNode(T value); //our key is the value in this example
    void insertNode(T value);
    bool deleteNode(T value);
    T* search(int value){
      if (searchNode(value)){
        TreeNode<T> *current = root;
        while(current->key != value){
          if(value < current->key){
            current = current->left;
          }
          else{
            current = current->right;
          }
        }
        return current->data;
      }
      else{
        return NULL;
      }
    }

    bool isEmpty(){
      return (size == 0);
    }
    unsigned int getSize(){
      return size;
    }
    int getMin();
    int getMax();
    void recPrint(TreeNode<T> *node);
    void printEntireTree();
    TreeNode<T>* getRoot(){
      return root;
    }

    TreeNode<T>* getSuccessor(TreeNode<T> *d); //d represents the node to be deleted
};

template <class T>
BST<T>::BST(){
  root = NULL;
  size = 0;
}
template <class T>
BST<T>::~BST(){
  //iterate and delete => 0(n)
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->key << endl; //cout << node->value << endl;
    recPrint(node->right);
  }
}

template <class T>
void BST<T>::printEntireTree(){
  recPrint(root);
}

template <class T>
int BST<T>::getMax(){
  TreeNode<T> *current = root;

  if(isEmpty())
    return NULL;

  while(current != NULL){
    current = current->right;
  }

  return current->key;
}

template <class T>
void BST<T>::insertNode(T value){
  //creat the node first
  TreeNode<T> *node = new TreeNode<T>(value); // passes/ initializes value into key
  if(isEmpty()){
    root = node;
  }
  else{
    //tree is not empty
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while (true){
      parent = current;

      if(value < current->key){
        //go left
        current = current->left;
        if(current == NULL){
          //found insertion point
          parent->left = node;
          break;
        }
      }
      else{
        //we go right
        current = current->right;
        if(current == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}

template <class T>
bool BST<T>::searchNode(T value){
  if(isEmpty())
    return false;
  else{
    //tree node is not empty, lets find the value
    TreeNode<T> *current = root;
    while(current->key != value){
      if(value < current->key)
        current = current->left;
      else
        current = current->right;
      if(current == NULL)
        return false;
    }
  }
  return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
  if(isEmpty())
    return false;

  //you can leverage search to determine whether value before proceeding
   TreeNode<T> *current = root;
   TreeNode<T> *parent = root;
   bool isLeftChild = true;

   //usual code to find a TreeNode
   while(current->key != k){
     parent = current;

     if(k < current->key){
       //go LeftChild
       isLeftChild = true;
       current = current->left;
     }
     else{
       //go right
       isLeftChild = false;
       current = current->right;
     }
     if(current == NULL)
      return false;
   }
   //if we make if here, we found our key/value
   //lets proceed to delete

   //case: node to be deleted, has no children, AKA leaf TreeNode
   if(current->left == NULL && current->right == NULL){
     if(current == root){
       root = NULL; //removed the root
     }
     else if(isLeftChild){
       parent->left = NULL;
     }
     else{
       //right child
       parent->right = NULL;
     }
   }
   //case: node to be deleted has one child, need to determine whther node has elft or right child
   else if(current->right == NULL){
     //node has one child and its a left
     //no right child
     if(current == root){
       root = current->left;
     }
     else if(isLeftChild){
       parent->left = current->left;
     }
     else{
       parent->right = current->left;
     }
   }

   else if(current->left == NULL){
     //node has one child and its a left
     //no right child
     if(current == root){
       root = current->right;
     }
     else if(isLeftChild){
       parent->left = current->right;
     }
     else{
       parent->right = current->right;
     }
   }
   else{
     //node to be deleted has two children
     TreeNode<T> *successor = getSuccessor(current);

     if(current == root){
       root = successor;
     }
     else if(isLeftChild){
       parent->left = successor;
     }
     else{
       parent->right = successor;
     }
     successor->left = current->left;
   }
   //delete current;
   size--;
   return true;
}

// d represents the node we are deleting
TreeNode<T>* BST::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  //once we exit the while loop, pointers should be in correct positions
  //we need to check whether or not the succesor is desendant of right child
  if(successor != d->right){
    sp->left = succesor->right;
    successor->right = d->right;
  }
  return successor;

}
*/

class BST
{
    private:
        TreeNode<T> *root;
        int size;

    public:
        BST()
        {
            root = NULL;
            size = 0;
        }

        ~BST(){};

        void insert(TreeNode<T> *node)
        {
            //TreeNode<T> *node = new TreeNode<T>(data);

            // TREE IS EMPTY
            if (root == NULL)
            {
                root = node;
            }

            else
            {
                TreeNode<T> *current = root; // STARTING POINT
                TreeNode<T> *parent; // FOR KEEPING TRACK OF WHO THE NEW PARENT WILL BE

                while (true)
                {
                    parent = current;

                    // GOING LEFT
                    if (node->key < current->key)
                    {
                        current = current->left;

                        // FOUND A LEAF
                        if (current == NULL)
                        {
                            parent->left = node;
                            break;
                        }
                    }

                    // GOING RIGHT
                    else
                    {
                        current = current->right;

                        // FOUND A LEAF
                        if (current == NULL)
                        {
                            parent->right = node;
                            break;
                        }
                    }
                }
            }

            size++;
        }

        bool isInTree(int k)
        {
            // EMPTY TREE
            if (root == NULL)
            {
                return false;
            }

            TreeNode<T> *current = root;

            // LOOK FOR NODE
            while (current->key != k)
            {
                // GOING LEFT
                if (k < current->key)
                {
                    current = current->left;
                }

                // GOING RIGHT
                else
                {
                    current = current->right;
                }

                // NODE NOT FOUND
                if (current == NULL)
                {
                    return false;
                }
            }

            return true;
        }

        T* search(int k)
        {
            if (isInTree(k))
            {
                TreeNode<T> *current = root;

                // LOOK FOR NODE
                while (current->key != k)
                {
                    // GOING LEFT
                    if (k < current->key)
                    {
                        current = current->left;
                    }

                    // GOING RIGHT
                    else
                    {
                        current = current->right;
                    }
                }

                return current->data;
            }

            else
            {
                return NULL;
            }
        }

        TreeNode<T>* getSuccessor(TreeNode<T> *n)
        {
            TreeNode<T> *successorParent = n;
            TreeNode<T> *successor = n;
            TreeNode<T> *current = n->right;

            while (current != NULL)
            {
                successorParent = successor;
                successor = current;
                current = current->left;
            }

            if (successor != n->right)
            {
                successorParent->left = successor->right;
                successor->right = n->right;
            }

            return successor;
        }

        bool deleteNode(int k)
        {
            // EMPTY TREE
            if (root == NULL)
            {
                return false;
            }

            TreeNode<T> *parent = root;
            TreeNode<T> *current = root;
            bool isLeft = true;

            // LOOK FOR NODE TO DELETE
            while (current->key != k)
            {
                parent = current;

                // GOING LEFT
                if (k < current->key)
                {
                    isLeft = true;

                    current = current->left;
                }

                // GOING RIGHT
                else
                {
                    isLeft = false;

                    current = current->right;
                }

                // NODE NOT FOUND
                if (current == NULL)
                {
                    return false;
                }
            }

            // IF WE GET HERE, WE FOUND NODE TO BE DELETED;
            // NOW WE CHECK OUR CASES

            // NO CHILDREN
            if (current->left == NULL && current->right == NULL)
            {
                // DELETING THE ROOT
                if (current == root)
                {
                    root = NULL;
                }

                else if (isLeft)
                {
                    parent->left = NULL;
                }

                else
                {
                    parent->right = NULL;
                }
            }

            // ONE CHILD, LEFT CHILD
            else if (current->right == NULL)
            {
                if (current == root)
                {
                    root = current->left;
                }

                else if (isLeft)
                {
                    parent->left = current->left;
                }

                else
                {
                    parent->right = current->left;
                }
            }

            // ONE CHILD, RIGHT CHILD
            else if (current->right == NULL)
            {
                if (current == root)
                {
                    root = current->right;
                }

                else if (isLeft)
                {
                    parent->left = current->right;
                }

                else
                {
                    parent->right = current->right;
                }
            }

            // TWO CHILDREN
            else
            {
                TreeNode<T> *successor = getSuccessor(current);

                if (current == root)
                {
                    root = successor;
                }

                else if (isLeft)
                {
                    parent->left = successor;
                }

                else
                {
                    parent->right = successor;
                }

                // LINK SUCCESSOR TO CURRENT'S LEFT CHILD
                successor->left = current->left;
            }

            size--;
            return true;
        }

        void print(TreeNode<T> *node)
        {
            if (node == NULL)
            {
                return;
            }

            print(node->left);
            cout << node->data << " | ";
            print(node->right);
        }

        void printTree()
        {
            print(root);
        }

        TreeNode<T>* getRoot()
        {
            return root;
        }

        int getSize()
        {
            return size;
        }

        bool isEmpty()
        {
            return (size == 0);
        }

        void printRecursion(TreeNode<T> *node, ofstream& outfile){
          if (node != NULL){
            printRecursion(node->left, outfile);
            outfile << node->data << endl;
            printRecursion(node->right, outfile);
          }
        }
};
