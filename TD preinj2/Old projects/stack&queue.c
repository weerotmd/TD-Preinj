#include "main.h"

typedef struct _node{
  int value;
  struct _node* next;
} Node;

Node* makeNode(int value) {
  Node* node = NULL;
  node = malloc(sizeof(Node));
  if (node == NULL) exit(1);
  node->next = NULL;
  node->value = value;
  return node;
}
Node* unshiftNode(Node* chain, int value) {
  Node* node = makeNode(value);
  node->next = chain;
  return node;
}
Node* pushNode(Node* chain, int value) {
  Node* node = makeNode(value);
  if (chain == NULL) return node;
  Node* pos = chain;
  while (pos->next != NULL) {
    pos = pos->next;
  }
  pos->next = node;
  return chain;
}
void displayChain(Node* chainStart) {
  Node* pos = chainStart;
  while (pos != NULL) {
    printf("%d", pos->value);
    pos = pos->next;
    if (pos != NULL) printf("->");
  };
  printf("\n");
}
void displayStackRecursive(Node* stack) {
  Node* pos = stack;
  if (pos == NULL) return;
  printf("%d", pos->value);
  if (pos->next != NULL) printf("->");
  else printf("\n");
  displayStackRecursive(pos->next);
}
Node* stackElement(Node* stack, int value) {
  stack = pushNode(stack, value);
  return stack;
}
Node* queueElement(Node* queue, int value) {
  queue = unshiftNode(queue, value);
  return queue;
}
Node* popElement(Node* stack, int* storeDeleted) {
  if (stack == NULL) return stack;
  Node* pos = stack;
  if (pos->next == NULL) {
    if (storeDeleted != NULL) *storeDeleted = pos->value;
    free(pos);
    stack = NULL;
    return stack;
  }
  while (pos->next->next != NULL) {
    pos = pos->next;
  }
  if (storeDeleted != NULL) *storeDeleted = pos->next->value;
  free(pos->next);
  pos->next = NULL;
  return stack;
}

int clientCart() {
  return rand()%50+1;
}

int isValidParenthesis(char* string) {
  Node* stack = NULL;
  int i = 0;
  char lastParenthesis = '0';
  while (string[i] != '\0') {
    if (string[i] == '(') {
      stack = stackElement(stack, string[i]);
    }
    else if (string[i] == ')') {
      char deleted;
      stack = popElement(stack, &deleted);
      if (deleted != '(') {
        return 0;
      }
    }
    else if (string[i] == '[') {
      stack = stackElement(stack, string[i]);
    }
    else if (string[i] == ']') {
      char deleted;
      stack = popElement(stack, &deleted);
      if (deleted != '[') {
        return 0;
      }
    }
    i++;
  }
  return stack == NULL;
}

/*Stack odd/even numbers
int main(int argc, char const *argv[]) {
  Node* stack = NULL;
  for (size_t i = 0; i < 20; i++) {
    stack = stackElement(stack, i+1);
  }
  displayStackRecursive(stack);
  Node* stackOdd = NULL;
  Node* stackEven = NULL;
  int deleted;
  while (stack != NULL) {
    stack = popElement(stack, &deleted);
    if (deleted%2) stackOdd = stackElement(stackOdd, deleted);
    else stackEven = stackElement(stackEven, deleted);
  }
  displayStackRecursive(stackEven);
  displayStackRecursive(stackOdd);
  return 0;
}*/
/*Shopping cart queue
int main(int argc, char const *argv[]) {
  Node* queue = NULL;
  srand(time(NULL));
  for (size_t i = 0; i < 3; i++) {
    queue = queueElement(queue, clientCart());
  }
  displayStackRecursive(queue);
  printf("Begining day.\n");
  while (queue != NULL) {
    int paid;
    queue = popElement(queue, &paid);
    if (rand()%3==0) for (size_t i = 0; i < rand()%3+1; i++) {
      queue = queueElement(queue, clientCart());
    }
    printf("Just paid %d articles.\n", paid);
    displayStackRecursive(queue);
  }
  return 0;
}
*/
/*Are parenthesis in the string valid? (Change int in structures and functions to char for support)
int main(int argc, char const *argv[]) {
  //char* myString = "a(((())))ddab";
  char* myString = "a(b[c()e]f)g(";
  //char* myString = "a(b(c()e)f)g";
  //char* myString = "a(b[c)d]e()f";
  //char* myString = "a(b[c)d]e()f";
  printf("Is valid: %d\n", isValidParenthesis(myString));
  return 0;
}*/
