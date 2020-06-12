#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *tree = NULL;  // any changes in any function made affect the global tree variable.

struct node *tree_insert(int n){
  struct node *new_node, *ptr, *preptr; // ptr is used to make preptr reach correct location
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;
  ptr = tree;
  if (tree == NULL)
    tree = new_node;
  while(ptr != NULL){
    preptr = ptr;
    if(n < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
  if(n < preptr->data)
    preptr->left = new_node;
  else
    preptr->right = new_node;
  return tree;
}

int level_counter = 0;
struct node *search(struct node *tree, int val){
  if (tree == NULL || tree->data == val)
    return tree;
  else if(val < tree->data)
    search(tree->left, val);
  else
    search(tree->right, val);
  level_counter++;
}

void inorder(struct node *tree){
  if (tree != NULL){
    inorder(tree->left);
    printf("\t%d", tree->data);
    inorder(tree->right);
  }
}

void preorder(struct node *tree){
  if (tree != NULL){
    printf("\t%d", tree->data);
    preorder(tree->left);
    preorder(tree->right);
  }
}

void postorder(struct node *tree){
  if (tree != NULL){
    postorder(tree->left);
    postorder(tree->right);
    printf("\t%d", tree->data);
  }
}

int total_nodes(struct node *tree){
  if (tree == NULL)
    return 0;   // return a number whenever doing recursion of this type
  else
    return (total_nodes(tree->left) + total_nodes(tree->right) + 1);
}

int internal_nodes(struct node *tree){
  if (tree == NULL)
    return 0;
  else if (tree->left == NULL && tree->right == NULL)
    return 0;
  else
    return internal_nodes(tree->left) + internal_nodes(tree->right) + 1;
}

int external_nodes(struct node *tree){
  if (tree == NULL)
    return 0;
  else if (tree->left == NULL && tree->right == NULL)
    return 1;
  else
    return external_nodes(tree->left) + external_nodes(tree->right);
}

struct node *mirror_tree(struct node *tree){
  struct node *temp;
  if (tree != NULL){
    mirror_tree(tree->left);
    mirror_tree(tree->right);
    temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;
  }
  return tree;
}

struct node *smallest_node(struct node *tree){  // smallest node of binary search tree means leftmost node
  if (tree == NULL || tree->left == NULL)
    return tree;
  else
    smallest_node(tree->left);
}

struct node *largest_node(struct node *tree){  // largest means rightmost node.
  if (tree == NULL || tree->right == NULL)
    return tree;
  else
    return largest_node(tree->right);
}

struct node *delete_element(struct node *tree, int val){
  if (tree == NULL)
    return tree;
  else if (val < tree->data)
    tree->left = delete_element(tree->left, val);
  // whatever deletion happens in 'else', the returned address of tree from there to be stored in these tree->left or tree->right locations of previous node.
  // func will delete node and return the changed address which need to be stored in previous node pointer.
  // so, prev node left pointer = address of new node after deletion.
  // multiple recursions to reach correct node & then store the changed address due to deletion, to node prev. than one deleted.
  else if (val > tree->data)
    tree->right = delete_element(tree->right, val);
  else{
    if (tree->left == NULL && tree->right == NULL){   // leaf node
      free(tree);  // deallocate memory of node
      tree = NULL; //the address of pointer set to NULL
      return tree;
    }
    else if (tree->left == NULL){
      struct node *temp;
      temp = tree;
      tree = tree->right; // move tree pointer to right side node
      free(temp);
      return tree;  // return address of right subtree of node(which is deleted) to second or third elseif statement of this func.
    }
    else if (tree->right == NULL){
      struct node *temp;
      temp = tree;
      tree = tree->left;
      free(temp);
      return tree;
    }
    else{
      struct node *large_node;
      large_node = largest_node(tree->left);  // either it's rightmost leaf node or secondlast right node of left subtree
      tree->data = large_node->data;
      tree->left = delete_element(tree->left, large_node->data); // delete that node with largest val in left subtree
      return tree;
    }
  }
}

int main(){
  int tree_val;
  printf("Enter values to be inserted in the  tree.\n");
  printf("Enter -1 to stop.\n");
  scanf("%d", &tree_val);
  while(tree_val != -1){
    tree_insert(tree_val);
    scanf("%d", &tree_val);
  }
  printf("\nInorder Traversal : ");
  inorder(tree);
  printf("\nPre-Order Traversal : ");
  preorder(tree);
  printf("\nPostOrder Traversal : ");
  postorder(tree);
  printf("\n\nTotal number of nodes in the tree : %d", total_nodes(tree));
  printf("\nTotal number of internal nodes : %d", internal_nodes(tree));
  printf("\nTotal number of external nodes : %d", external_nodes(tree));
  printf("\nSmallest node in the tree : %d", smallest_node(tree)->data);
  printf("\nLargest node of the tree : %d", largest_node(tree)->data);
  printf("\nEnter value to search : ");
  scanf("%d", &tree_val);
  printf("\nElement found at %d level.",search(tree, tree_val));
  printf("\nEnter element to delete : ");
  int del_val;
  scanf("%d", &del_val);
  delete_element(tree, del_val);
  printf("\nElement deleted successfully.");
  mirror_tree(tree);
  printf("\n\nMirror tree has been created.\n");
  printf("\nMirror tree Inorder Traversal : ");
  inorder(tree);
  printf("\nMirror tree Pre-Order Traversal : ");
  preorder(tree);
  printf("\nMirror tree PostOrder Traversal : ");
  postorder(tree);
  return 0;
}
