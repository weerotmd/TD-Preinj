#include "main.h"

typedef struct _treeNode{
  int value;
  struct _treeNode* right;
  struct _treeNode* left;
} TreeNode;

TreeNode* makeTreeNode(int value) {
  TreeNode* treeNode = NULL;
  treeNode = malloc(sizeof(TreeNode));
  if (treeNode == NULL) exit(1);
  treeNode->right = NULL;
  treeNode->left = NULL;
  treeNode->value = value;
  return treeNode;
}

typedef struct _queueNode{
  TreeNode* treeNode;
  struct _queueNode* next;
} QueueNode;

QueueNode* makeQueueNode(TreeNode* treeNode) {
  QueueNode* node = NULL;
  node = malloc(sizeof(QueueNode));
  if (node == NULL) exit(1);
  node->next = NULL;
  node->treeNode = treeNode;
  return node;
}
void pushQueueNode(QueueNode** queue, TreeNode* treeNode) {
  QueueNode* node = makeQueueNode(treeNode);
  if (*queue == NULL) {
    *queue = node;
    return;
  }
  QueueNode* pos = *queue;
  while (pos->next != NULL) {
    pos = pos->next;
  }
  pos->next = node;
}
TreeNode* shiftQueueNode(QueueNode** queue) {
  if (*queue == NULL) return NULL;
  QueueNode* head = (*queue);
  TreeNode* treeNode = (*queue)->treeNode;
  *queue = head->next;
  free(head);
  return treeNode;
}

int isEmpty(TreeNode* treeNode){
  return treeNode == NULL;
}
int isLeaf(TreeNode* treeNode){
  if (treeNode == NULL) return 1;
  return treeNode->left == NULL && treeNode->right == NULL;
}
int element(TreeNode* treeNode) {
  return treeNode->value;
}
int hasLeftChild(TreeNode* treeNode) {
  if (treeNode == NULL) return 0;
  return treeNode->left != NULL;
}
int hasRightChild(TreeNode* treeNode) {
  if (treeNode == NULL) return 0;
  return treeNode->right != NULL;
}
void addLeftChild(TreeNode** treeNode, int n) {
  if (*treeNode == NULL) return;
  (*treeNode)->left = makeTreeNode(n);
  //return (*treeNode)->left;
}
void addRightChild(TreeNode** treeNode, int n) {
  if (*treeNode == NULL) return;
  (*treeNode)->right = makeTreeNode(n);
  //return (*treeNode)->right;
}
void displayTreeNode(TreeNode* treeNode) {
  printf("%d,", treeNode->value);
}
void changeRoot(TreeNode** treeNode, int n) {
  if (*treeNode == NULL) return;
  (*treeNode)->value = n;
}
void deleteAllChilds(TreeNode** treeNode) {
  if (*treeNode == NULL) return;
  deleteAllChilds(&(*treeNode)->left);
  deleteAllChilds(&(*treeNode)->right);
  free(*treeNode);
  *treeNode = NULL;
}
void deleteLeftChild(TreeNode** treeNode) {
  if (*treeNode == NULL || (*treeNode)->left == NULL) return;
  deleteAllChilds(&(*treeNode)->left);
  (*treeNode)->left = NULL;
}
void deleteRightChild(TreeNode** treeNode) {
  if (*treeNode == NULL || (*treeNode)->right == NULL) return;
  deleteAllChilds(&(*treeNode)->right);
  (*treeNode)->right = NULL;
}
int leafCount(TreeNode* treeNode) {
  int leaves = 0;
  if (treeNode == NULL) return 1;
  QueueNode* queue = NULL;
  pushQueueNode(&queue, treeNode);
  while (queue != NULL) {
    TreeNode* node = shiftQueueNode(&queue);
    if (isLeaf(node)) leaves++;
    if (hasLeftChild(node)) pushQueueNode(&queue, node->left);
    if (hasRightChild(node)) pushQueueNode(&queue, node->right);
  }
  return leaves;
}
int treeSize(TreeNode* treeNode) {
  int size = 0;
  if (treeNode == NULL) return 1;
  QueueNode* queue = NULL;
  pushQueueNode(&queue, treeNode);
  while (queue != NULL) {
    TreeNode* node = shiftQueueNode(&queue);
    if (!isLeaf(node)) size++;
    if (hasLeftChild(node)) pushQueueNode(&queue, node->left);
    if (hasRightChild(node)) pushQueueNode(&queue, node->right);
  }
  return size;
}
int treeHeight(TreeNode* treeNode) {
  if (treeNode == NULL) return -1;
  int left = treeHeight(treeNode->left);
  int right = treeHeight(treeNode->right);
  return 1 + (left > right ? left : right);
}

void inorderTraversal(TreeNode* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ", root->value);
  inorderTraversal(root->right);
}
void preorderTraversal(TreeNode* root) {
  if (root == NULL) return;
  printf("%d, ", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d, ", root->value);
}
void breadthfirstTraversal(TreeNode* root) {
  if (root == NULL) return;
  QueueNode* queue = NULL;
  pushQueueNode(&queue, root);
  while (queue != NULL) {
    TreeNode* node = shiftQueueNode(&queue);
    printf("%d, ", node->value);
    if (hasLeftChild(node)) pushQueueNode(&queue, node->left);
    if (hasRightChild(node)) pushQueueNode(&queue, node->right);
  }
  printf("\n");
}

int searchBST(TreeNode* treeNode, int n) {
  if (treeNode == NULL) return 0;
  else if (n < treeNode->value) {
    return searchBST(treeNode->left, n);
  }
  else if (n > treeNode->value) {
    return searchBST(treeNode->right, n);
  }
  return 1;
}

TreeNode* addChildBST(TreeNode** treeNode, int n) {
  if (*treeNode == NULL) *treeNode = makeTreeNode(n);
  else if (n < element(*treeNode)) {
    (*treeNode)->left = addChildBST(&(*treeNode)->left, n);
  }
  else if (n > element(*treeNode)) {
    (*treeNode)->right = addChildBST(&(*treeNode)->right, n);
  }
  return *treeNode;
}
TreeNode* addChildBSTIterative(TreeNode** treeNode, int n) {
  if ((*treeNode) == NULL) return makeTreeNode(n);
  TreeNode* pos = *treeNode;
  TreeNode* parent = NULL;
  while (pos != NULL) {
    parent = pos;
    if (n < pos->value) {
      pos = pos->left;
    }
    else if (n > pos->value) {
      pos = pos->right;
    }
    else return *treeNode;
  }
  if (n < parent->value) parent->left = makeTreeNode(n);
  if (n > parent->value) parent->right = makeTreeNode(n);
  return *treeNode;
}
TreeNode* deleteMax(TreeNode** tree, int* nodeToDelete) {
  TreeNode* biggestNode = *tree;
  if (hasRightChild(*tree)) {
    (*tree)->right = deleteMax(&(*tree)->right, nodeToDelete);
  }
  else {
    *nodeToDelete = (*tree)->value;
    biggestNode = *tree;
    *tree = (*tree)->left;
    free(biggestNode);
  }
  return *tree;
}
TreeNode* deleteElementBST(TreeNode** treeNode, int n) {
  if (*treeNode == NULL) return *treeNode;
  else if (n > (*treeNode)->value) {
    (*treeNode)->right = deleteElementBST(&(*treeNode)->right, n);
  }
  else if (n < (*treeNode)->value) {
    (*treeNode)->left = deleteElementBST(&(*treeNode)->left, n);
  }
  else if (!hasLeftChild(*treeNode)) {
    TreeNode* rightNode = *treeNode;
    *treeNode = (*treeNode)->right;
    free(rightNode);
  }
  else if (!hasRightChild(*treeNode)) {
    TreeNode* leftNode = *treeNode;
    *treeNode = (*treeNode)->left;
    free(leftNode);
  }
  else {
    (*treeNode)->left = deleteMax(&(*treeNode)->left, &(*treeNode)->value);
  }
  return *treeNode;
}

void printTree(TreeNode *root, int space) {//ChatGPT function
    if (root == NULL) return;
    // Increase distance between levels
    int indent = 5;
    space += indent;
    // Process right child first (will be printed on top)
    printTree(root->right, space);
    // Print current node after space count
    printf("\n");
    for (int i = indent; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
    // Process left child (will be printed below)
    printTree(root->left, space);
}

int main(int argc, char const *argv[]) {
  TreeNode* root = makeTreeNode(10);
  //displayTreeNode(root);
  addChildBST(&root, 3);
  addChildBSTIterative(&root, 5);
  addChildBST(&root, 15);
  addChildBST(&root, 20);
  addChildBSTIterative(&root, 12);
  addChildBST(&root, 7);
  addChildBSTIterative(&root, 45);
  addChildBST(&root, 9);
  printTree(root, 0);
  inorderTraversal(root);
  printf("\n");
  deleteElementBST(&root, 15);
  deleteElementBST(&root, 7);
  printTree(root, 0);
  inorderTraversal(root);
  printf("\n");
  return 0;
}
