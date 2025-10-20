#include "main.h"

typedef struct _node{
  char value[21];
  struct _node* next;
  struct _node* previous;
} Node;

Node* makeNode(char* value) {
  if (strlen(value) > 20) {
    printf("String is more than 20 characters: %s\n", value);
    exit(1);
  }
  Node* node = NULL;
  node = malloc(sizeof(Node));
  if (node == NULL) exit(1);
  node->next = NULL;
  node->previous = NULL;
  memcpy(node->value, value, strlen(value)+1);
  return node;
}
Node* unshiftNode(Node* chain, char* value) {
  Node* node = makeNode(value);
  if (chain != NULL) chain->previous = node;
  node->next = chain;
  return node;
}
Node* pushNode(Node* chain, char* value) {
  Node* node = makeNode(value);
  if (chain == NULL) return node;
  Node* pos = chain;
  while (pos->next != NULL) {
    pos = pos->next;
  }
  pos->next = node;
  node->previous = pos;
  return chain;
}
void displayChain(Node* chainStart) {
  Node* pos = chainStart;
  while (pos != NULL) {
    printf("%s", pos->value);
    pos = pos->next;
    if (pos != NULL) printf("->");
  };
  printf("\n");
}
void displayStackRecursive(Node* stack) {
  Node* pos = stack;
  if (pos == NULL) return;
  printf("%s", pos->value);
  if (pos->next != NULL) printf("->");
  else printf("\n");
  displayStackRecursive(pos->next);
}
void displayStackRecursivePrevious(Node* stackEnd) {
  Node* pos = stackEnd;
  if (pos == NULL) return;
  printf("%s", pos->value);
  if (pos->previous != NULL) printf("<-");
  else printf("\n");
  displayStackRecursivePrevious(pos->previous);
}
Node* stackElement(Node* stack, char* value) {
  stack = pushNode(stack, value);
  return stack;
}
Node* queueElement(Node* queue, char* value) {
  queue = unshiftNode(queue, value);
  return queue;
}
Node* popElement(Node* stack, char* storeDeleted) {
  if (stack == NULL) return stack;
  Node* pos = stack;
  if (pos->next == NULL) {
    if (storeDeleted != NULL) memcpy(storeDeleted, pos->value, strlen(pos->value)+1);
    free(pos);
    stack = NULL;
    return stack;
  }
  while (pos->next->next != NULL) {
    pos = pos->next;
  }
  if (storeDeleted != NULL) memcpy(storeDeleted, pos->next->value, strlen(pos->next->value)+1);
  free(pos->next);
  pos->next = NULL;
  return stack;
}
Node* invertListWithCopy(Node* chain) {
  if (chain == NULL) return chain;
  Node* invertedChain = NULL;
  Node* pos = chain;
  while (pos != NULL) {
    invertedChain = unshiftNode(invertedChain, pos->value);
    pos = pos->next;
  }
  return invertedChain;
}
int compareWords(char* wordA, char* wordB) {
  int i = 0;
  while (wordA[i] != '\0' && wordB[i] != '\0') {
    if (wordA[i] < wordB[i]) return 1;
    if (wordB[i] < wordA[i]) return 0;
    i++;
  }
  return wordA[i] == '\0';
}
Node* insertNodeAlphabetical(Node* chain, char* value) {
  Node* node = makeNode(value);
  if (chain == NULL) return node;
  if (compareWords(value, chain->value)) {
    chain->previous = node;
    node->next = chain;
    return node;
  }
  Node* pos = chain;
  while (pos->next != NULL && compareWords(pos->next->value, value)) {
    pos = pos->next;
  }
  if (pos->next != NULL) pos->next->previous = node;
  node->next = pos->next;
  pos->next = node;
  node->previous = pos;
  return chain;
}

/*int main(int argc, int const *argv[]) {
  Node* words = NULL;
  words = insertNodeAlphabetical(words, "start");
  words = insertNodeAlphabetical(words, "test");
  words = insertNodeAlphabetical(words, "apple");
  words = insertNodeAlphabetical(words, "hello");
  words = insertNodeAlphabetical(words, "bannana");
  words = insertNodeAlphabetical(words, "snippet");
  words = insertNodeAlphabetical(words, "would");
  words = insertNodeAlphabetical(words, "iterate");
  words = insertNodeAlphabetical(words, "function");
  words = insertNodeAlphabetical(words, "expected");
  displayStackRecursive(words);
  Node* end = words;
  while (end->next != NULL) {
    end = end->next;
  }
  displayStackRecursivePrevious(end);
  return 0;
}*/
