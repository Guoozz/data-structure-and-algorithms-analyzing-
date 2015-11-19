#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct tree_node{
  int key;
  struct tree_node * left;
  struct tree_node * right;
  struct tree_node * parent;
}tree_node;

typedef struct tree{
  tree_node* root;
  char* info;
}tree;

typedef tree_node * search_tree_node;
typedef tree* search_tree;

search_tree create_search_tree(void)
{
  search_tree T = (search_tree) malloc(sizeof(tree));
  if(T != NULL){
    T->root = NULL;
    char* tree_info = (char*)malloc(sizeof("Binary Search Tree"));
    if (tree_info != NULL)
      T->info = tree_info;
    else exit(1);
  }
  else exit(1);
  return T;
}

/* 插入的节点总是被插入树的叶节点 */
void search_tree_insert(search_tree T,search_tree_node node)
{
  int key = node->key;
  search_tree_node tmp = T->root;
  search_tree_node tmp_parent = NULL;
  while(tmp != NULL){
    tmp_parent = tmp;
    if(key < tmp->key)
      tmp = tmp->left;
    else
      tmp = tmp->right;
  }
  if(tmp_parent == NULL){
    T->root = node;
  } //empty tree
  else if(key < tmp_parent->key){
    tmp_parent->left = node;
  }
  else
    tmp_parent->right = node;
  node->parent = tmp_parent;
}

search_tree_node create_search_tree_node(int key)
{
  search_tree_node node = (search_tree_node) malloc(sizeof(tree_node));
  if(node != NULL){
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
  }
  return node;
}

void delete_search_tree_node(search_tree_node root)
{
  if(root != NULL){
    delete_search_tree_node(root->left);
    free(root);
    delete_search_tree_node(root->right);
  }
}

void delete_search_tree(search_tree t)
{
  delete_search_tree_node(t->root);
  free(t->info);
  free(t);
}

void in_order_search_tree(search_tree_node root)
{
    if(root != NULL){
      in_order_search_tree(root->left);
      printf("%d,",root->key);
      in_order_search_tree(root->right);
  }
}

int main()
{
  search_tree t = create_search_tree();
  for(int i = 0;i < 200;++i){
    search_tree_node node = create_search_tree_node(i);
    search_tree_insert(t,node);
  }
  in_order_search_tree(t->root);
  malloc_stats();
  delete_search_tree(t);
  malloc_stats();
  return 0;
}
