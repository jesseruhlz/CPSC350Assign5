class TreeNode{
  public:
    TreeNode();
    TreeNode(int k);
    ~TreeNode();

    int key;
    //could do like <T> data for bst with any data type
    //or could let Student class be your data
    TreeNode *left;
    TreeNode *right;
};

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

class BST{
  private:
    TreeNode *root;
  public:
    BST();
    ~BST();

    bool searchNode(int value); //our key is the value in this example
    void insertNode(int value);
    bool deleteNode(int value);

    bool isEmpty();
    unsigned int getSize();
    int getMin();
    int getMax();
    void recPrint(TreeNode *node);

    TreeNode* getSuccessor(TreeNode *d); //d represents the node to be deleted
};

BST::BST(){
  root = NULL;
}

BST::BST(){
  //iterate and delete => 0(n)
}

void BST::recPrint(TreeNode * node){
  if(node != NULL){
    recPrint(node->left);
    cout << node->key << endl; //cout << node->value << endl;
    recPrint(node->right);
  }
}

void BST::printEntireTree(){
  recPrint(root);
}

int BST::getMax(){
  TreeNode *current = root;

  if(isEmpty())
    return NULL;

  while(current-> != NULL){
    current = current->right;
  }

  return current->key;
}

void BST::insertNode(int value){
  //creat the node first
  TreeNode *node = new TreeNode(value); // passes/ initializes value into key
  if(isEmpty()){
    root = node;
  }
  else{
    //tree is not empty
    TreeNode *current = root;
    TreeNode *parent = NULL;

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
}

bool BST::searchNode(int value){
  if(isEmpty())
    return false;
  else{
    //tree node is not empty, lets find the value
    TreeNode *current = root;
    while(current->key !=){
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

bool BST::deleteNode(int k){
  if(isEmpty())
    return false;

  //you can leverage search to determine whether value before proceeding
   TreeNode *current = root;
   TreeNode * parent = root;
   bool isLeftChild = true;

   //usual code to find a TreeNode
   while(current->key != k){
     parent = current;

     if(k < current->key){
       //go LeftChild
       isLeftChild = true;
       current = curent->left;
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

   else if(curent->left == NULL){
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
     TreeNode *successor = getSuccessor(current);

     if(current == root){
       root = successor;
     }
     else if(isLeftNode){
       parent->left = successor;
     }
     else{
       parent->right = successor;
     }
     successor->left = current->left;
   }
   //delete current;
   return true;
}

// d represents the node we are deleting
TreeNode* BST::getSuccessor(TreeNode *d){
  TreeNode *sp = d;
  TreeNode *successor = d;
  TreeNode *current = d->right;

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
