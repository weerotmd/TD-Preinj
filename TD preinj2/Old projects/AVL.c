#include "main.h"

int max2(int a, int b) {
  return a >= b ? a : b;
}
int max3(int a, int b, int c) {
  return a >= b ? a >= c ? a : c : b >= c ? b : c;
}
int min2(int a, int b) {
  return a <= b ? a : b;
}
int min3(int a, int b, int c) {
  return a <= b ? a <= c ? a : c : b <= c ? b : c;
}

typedef struct _treeNode{
  int value;
  struct _treeNode* right;
  struct _treeNode* left;
  int balanced;
} TreeNode;

TreeNode* makeTreeNode(int value) {
  TreeNode* treeNode = NULL;
  treeNode = malloc(sizeof(TreeNode));
  if (treeNode == NULL) exit(1);
  treeNode->right = NULL;
  treeNode->left = NULL;
  treeNode->value = value;
  treeNode->balanced = 0;
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
  if (treeNode == NULL) return 0;
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
  if (treeNode == NULL) return 0;
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
TreeNode* searchBST(TreeNode* treeNode, int n) {
  if (treeNode == NULL) return NULL;
  else if (n < treeNode->value) {
    return searchBST(treeNode->left, n);
  }
  else if (n > treeNode->value) {
    return searchBST(treeNode->right, n);
  }
  return treeNode;
}
int existsInBST(TreeNode* treeNode, int n) {
  if (treeNode == NULL) return 0;
  else if (n < treeNode->value) {
    return existsInBST(treeNode->left, n);
  }
  else if (n > treeNode->value) {
    return existsInBST(treeNode->right, n);
  }
  return 1;
}

TreeNode* rotateTreeLeft(TreeNode** treeNode) {
  if (*treeNode == NULL || (*treeNode)->right == NULL) return *treeNode;
  TreeNode* pivot;
  int balanceTreeNode, balancePivot;
  pivot = (*treeNode)->right;
  (*treeNode)->right = pivot->left;
  pivot->left = (*treeNode);
  balanceTreeNode = (*treeNode)->balanced;
  balancePivot = pivot->balanced;
  (*treeNode)->balanced = balanceTreeNode - max2(balancePivot, 0) - 1;
  pivot->balanced = min3(balanceTreeNode-2, balanceTreeNode+balancePivot-2, balancePivot-1);
  (*treeNode) = pivot;
  return *treeNode;
}
TreeNode* rotateTreeRight(TreeNode** treeNode) {
  if (*treeNode == NULL || (*treeNode)->left == NULL) return *treeNode;
  TreeNode* pivot;
  int balanceTreeNode, balancePivot;
  pivot = (*treeNode)->left;
  (*treeNode)->left = pivot->right;
  pivot->right = (*treeNode);
  balanceTreeNode = (*treeNode)->balanced;
  balancePivot = pivot->balanced;
  (*treeNode)->balanced = balanceTreeNode - min2(balancePivot, 0) + 1;
  pivot->balanced = max3(balanceTreeNode+2, balanceTreeNode+balancePivot+2, balancePivot+1);
  (*treeNode) = pivot;
  return *treeNode;
}
TreeNode* doubleRotateTreeLeft(TreeNode** treeNode) {
  (*treeNode)->right = rotateTreeRight(&(*treeNode)->right);
  return rotateTreeLeft(treeNode);
}
TreeNode* doubleRotateTreeRight(TreeNode** treeNode) {
  (*treeNode)->left = rotateTreeLeft(&(*treeNode)->left);
  return rotateTreeRight(treeNode);
}

TreeNode* balanceAVL(TreeNode** treeNode) {
  if ((*treeNode)->balanced >= 2) {
    if ((*treeNode)->right->balanced >= 0) {
      return rotateTreeLeft(treeNode);
    } else {
      return doubleRotateTreeLeft(treeNode);
    }
  }
  else if ((*treeNode)->balanced <= -2) {
    if ((*treeNode)->left->balanced <= 0) {
      return rotateTreeRight(treeNode);
    } else {
      return doubleRotateTreeRight(treeNode);
    }
  }
  return *treeNode;
}

TreeNode* addChildAVL(TreeNode** treeNode, int n, int* h) {
  if (*treeNode == NULL) {
    *h = 1;
    *treeNode = makeTreeNode(n);
  }
  else if (n < (*treeNode)->value) {
    (*treeNode)->left = addChildAVL(&(*treeNode)->left, n, h);
    *h = -*h;
  }
  else if (n > (*treeNode)->value) {
    (*treeNode)->right = addChildAVL(&(*treeNode)->right, n, h);
  }
  else {
    *h = 0;
    return *treeNode;
  }
  if (*h != 0) {
    (*treeNode)->balanced = (*treeNode)->balanced + *h;
    *treeNode = balanceAVL(treeNode);
    if ((*treeNode)->balanced == 0) {
      *h = 0;
    } else {
      *h = 1;
    }
  }
  return *treeNode;
}
TreeNode* deleteMin(TreeNode** tree, int* nodeToDelete, int* h) {
  if (!hasLeftChild(*tree)) {
    *nodeToDelete = (*tree)->value;
    TreeNode* smallestNode = *tree;
    *h = -1;
    smallestNode = *tree;
    *tree = (*tree)->right;
    free(smallestNode);
    return *tree;
  }
  else {
    (*tree)->left = deleteMin(&(*tree)->left, nodeToDelete, h);
    *h = -*h;
  }
  if (*h != 0) {
    (*tree)->balanced = (*tree)->balanced + *h;
    *tree = balanceAVL(tree);
    if ((*tree)->balanced == 0) {
      *h = -1;
    } else {
      *h = 0;
    }
  }
  return *tree;
}
TreeNode* deleteElementAVL(TreeNode** treeNode, int n, int* h) {
  if (*treeNode == NULL) {
    *h = 0;
    return *treeNode;
  }
  else if (n > (*treeNode)->value) {
    (*treeNode)->right = deleteElementAVL(&(*treeNode)->right, n, h);
  }
  else if (n < (*treeNode)->value) {
    (*treeNode)->left = deleteElementAVL(&(*treeNode)->left, n, h);
    *h = -*h;
  }
  else if (hasRightChild(*treeNode)) {
    (*treeNode)->right = deleteMin(&(*treeNode)->right, &(*treeNode)->value, h);
  }
  else {
    TreeNode* leftNode = *treeNode;
    *treeNode = (*treeNode)->left;
    free(leftNode);
    *h = -1;
    return *treeNode;
  }
  if (*h != 0) {
    (*treeNode)->balanced = (*treeNode)->balanced + *h;
    *treeNode = balanceAVL(treeNode);
    if ((*treeNode)->balanced == 0) {
      *h = -1;
    } else {
      *h = 0;
    }
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
  int h;
  TreeNode* root = makeTreeNode(10);
  addChildAVL(&root, 3, &h);
  addChildAVL(&root, 5, &h);
  addChildAVL(&root, 15, &h);
  addChildAVL(&root, 20, &h);
  addChildAVL(&root, 12, &h);
  addChildAVL(&root, 7, &h);
  addChildAVL(&root, 9, &h);
  printTree(root, 0);
  inorderTraversal(root);
  printf("\n");
  deleteElementAVL(&root, 5, &h);
  deleteElementAVL(&root, 12, &h);
  printTree(root, 0);
  inorderTraversal(root);
  printf("\n");
  return 0;
}
