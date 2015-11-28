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

void free_search_tree_node(search_tree_node root)
{
  if(root != NULL){
    free_search_tree_node(root->left);
    free(root);
    free_search_tree_node(root->right);
  }
}

void free_search_tree(search_tree t)
{
  free_search_tree_node(t->root);
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

search_tree_node search_tree_maximum(search_tree_node root)
{
  if(root == NULL)
    return root;

  while(root->right != NULL)
    root = root->right;

  return root;
}

search_tree_node search_tree_minimum(search_tree_node root)
{
  if(root == NULL)
    return NULL;

  while(root->left != NULL)
    root = root->left;

  return root;
}

//中序遍历的前驱和后继

search_tree_node search_tree_successor(search_tree_node node)
{
  if(node->right != NULL)
    return search_tree_minimum(node->right);

  search_tree_node parent = node->parent;

  while(parent != NULL && parent->right == node){
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

search_tree_node search_tree_predecessor(search_tree_node node)
{
  if(node->left != NULL)
    return search_tree_maximum(node->left);

  search_tree_node parent = node->parent;

  while(parent != NULL && parent->left == node){
    node = parent;
    parent = parent->parent;
  }

  return parent;
}

search_tree_node search_tree_find(search_tree_node root,int key)
{
  if(root == NULL)
    return NULL;

  if(key < root->key)
    return search_tree_find(root->left,key);
  else if(key > root->key)
    return search_tree_find(root->right,key);
  return root;
}

int main()
{
  search_tree t = create_search_tree();

  for(int i = 0;i < 200;++i){
    search_tree_node node = create_search_tree_node(i);
    search_tree_insert(t,node);
  }

  in_order_search_tree(t->root);
  putchar('\n');

  int maximum = search_tree_maximum(t->root)->key;
  int minimum = search_tree_minimum(t->root)->key;
  printf("maximum element:%d\nminimum element:%d\n",maximum,minimum);

  search_tree_node t1 = search_tree_find(t->root,0);
  search_tree_node t2 = search_tree_find(t->root,199);
  search_tree_node t3 = search_tree_find(t->root,200);
  if(t1 != NULL) printf("t1:%d\n",t1->key);
  if(t2 != NULL) printf("t2:%d\n",t2->key);
  if(t3 != NULL) printf("t3:%d\n",t3->key);

  search_tree_node t1_suc = search_tree_successor(t1);
  search_tree_node t2_pre = search_tree_predecessor(t2);
  search_tree_node t2_suc = search_tree_successor(t2);
  if(t2_suc != NULL) printf("t2_suc:%d\n",t2_suc->key);

  free_search_tree(t);

  malloc_stats();
  return 0;
}
