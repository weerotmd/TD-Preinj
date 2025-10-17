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
  hasLeftChild(treeNode);
  hasRightChild(treeNode);
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

void preorderTraversal(TreeNode* root) {
  if (root == NULL) return;
  printf("%d, ", root->value);
  if (hasLeftChild(root)) preorderTraversal(root->left);
  if (hasRightChild(root)) preorderTraversal(root->right);
}
void postorderTraversal(TreeNode* root) {
  if (root == NULL) return;
  if (hasLeftChild(root)) postorderTraversal(root->left);
  if (hasRightChild(root)) postorderTraversal(root->right);
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
void displayTree(TreeNode* root) {
  TreeNode* pos = root;
  while (pos != NULL) {
    printf("%d", pos->value);
    pos = pos->left;
    if (pos != NULL) printf("->");
  };
  printf("\n");
}
void printTree(TreeNode *root, int space) {
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
  TreeNode* root = makeTreeNode(1);
  displayTreeNode(root);
  addLeftChild(&root, 2);
  addLeftChild(&root->left, 3);
  addLeftChild(&root->left->left, 4);
  addRightChild(&root->left->left, 5);
  addRightChild(&root->left, 6);
  addRightChild(&root->left->right, 7);
  addRightChild(&root, 8);
  addLeftChild(&root->right, 9);
  addRightChild(&root->right, 10);
  printTree(root, 0);
  preorderTraversal(root);
  printf("\n");
  postorderTraversal(root);
  printf("\n");
  breadthfirstTraversal(root);
  printf("Leaves: %d\n", leafCount(root));
  deleteLeftChild(&root);
  printTree(root, 0);
  printf("Leaves: %d\n", leafCount(root));
  return 0;
}
