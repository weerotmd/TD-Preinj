#include "main.h"
/*
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
}*/
typedef struct _pancake{
  int size;
  struct _pancake* next;
} Pancake;

Pancake makePancake(int size) {
  Pancake pancake;
  pancake.next = NULL;
  //pancake.previous = NULL;
  pancake.size = size;
  return pancake;
}
Pancake* queuePancake(Pancake* queue, Pancake pancake) {
  Pancake* newPancake = NULL;
  newPancake = malloc(sizeof(Pancake));
  if (newPancake == NULL) exit(1);
  //newPancake->previous = NULL;
  newPancake->size = pancake.size;
  //if (queue != NULL) queue->previous = newPancake;
  newPancake->next = queue;
  return newPancake;
}
Pancake* stackPancake(Pancake* stack, Pancake pancake) {
  /*Stack at the end
  Pancake* newPancake = NULL;
  newPancake = malloc(sizeof(Pancake));
  if (newPancake == NULL) exit(1);
  newPancake->size = pancake.size;
  if (stack == NULL) return newPancake;
  Pancake* pos = stack;
  while (pos->next != NULL) {
    pos = pos->next;
  }
  pos->next = newPancake;
  //newPancake->previous = pos;
  return stack;*/
  Pancake* newPancake = NULL;
  newPancake = malloc(sizeof(Pancake));
  if (newPancake == NULL) exit(1);
  newPancake->size = pancake.size;
  newPancake->next = stack;
  return newPancake;
}
Pancake* popPancake(Pancake* stack, int* storeDeleted) {
  if (stack == NULL) return stack;
  Pancake* pos = stack;
  if (pos->next == NULL) {
    if (storeDeleted != NULL) *storeDeleted = pos->size;
    free(pos);
    stack = NULL;
    return stack;
  }
  while (pos->next->next != NULL) {
    pos = pos->next;
  }
  if (storeDeleted != NULL) *storeDeleted = pos->next->size;
  free(pos->next);
  pos->next = NULL;
  return stack;
}
Pancake* shiftPancake(Pancake* stack, int* storeDeleted) {
  if (stack == NULL) return stack;
   Pancake* newHead = stack->next;
   if (storeDeleted != NULL) {
       *storeDeleted = stack->size;
   }
   free(stack);
   return newHead;
}
void displayPancakeStack(Pancake* stack) {
  Pancake* pos = stack;
  if (pos == NULL) return;
  printf("%d", pos->size);
  if (pos->next != NULL) printf("->");
  else printf("\n");
  displayPancakeStack(pos->next);
}
int pancakeStackOrdered(Pancake* stack) {
  Pancake* pos = stack;
  if (pos == NULL) return 1;
  while (pos->next != NULL && pos->size < pos->next->size) {
    pos = pos->next;
  }
  return pos->next == NULL;
}
int biggestPancakeEver(Pancake* stack) {
  Pancake* pos = stack;
  if (pos == NULL) return -1;
  int biggest = 0;
  int biggestPos = 0;
  int i = 1;
  while (pos->next != NULL) {
    pos = pos->next;
    if (pos->size > biggest) {
      biggestPos = i;
      biggest = pos->size;
    }
    i++;
  }
  return biggestPos;
}
Pancake* invertPancakes(Pancake* stack, int n) {
  if (stack == NULL) return stack;
  Pancake* invertedStack = NULL;
  Pancake* pos = stack;
  int i = 0;
  while (pos != NULL && i < n) {
    Pancake* newPancake = NULL;
    newPancake = malloc(sizeof(Pancake));
    if (newPancake == NULL) exit(1);
    newPancake->size = pos->size;
    newPancake->next = invertedStack;
    invertedStack = newPancake;
    pos = pos->next;
    i++;
  }
  Pancake* tail = invertedStack;
  while (tail && tail->next != NULL) {
    tail = tail->next;
  }
  if (tail != NULL) {
    tail->next = pos;
  }
  return invertedStack;
}
Pancake* invertBiggest(Pancake* stack) {
  return invertPancakes(stack, biggestPancakeEver(stack)+1);
}

Pancake* sortStack(Pancake* stack) {
  while (!pancakeStackOrdered(stack)) {
    stack = invertBiggest(stack);
  }
  return stack;
}



int main(int argc, int const *argv[]) {
  Pancake* pancakeStack = NULL;
  pancakeStack = stackPancake(pancakeStack, makePancake(18));
  pancakeStack = stackPancake(pancakeStack, makePancake(12));
  pancakeStack = queuePancake(pancakeStack, makePancake(9));
  pancakeStack = queuePancake(pancakeStack, makePancake(15));
  pancakeStack = queuePancake(pancakeStack, makePancake(3));
  pancakeStack = queuePancake(pancakeStack, makePancake(7));
  pancakeStack = queuePancake(pancakeStack, makePancake(5));
  pancakeStack = shiftPancake(pancakeStack, NULL);
  displayPancakeStack(pancakeStack);
  printf("Is ordered %d\n", pancakeStackOrdered(pancakeStack));
  sortStack(pancakeStack);
  printf("Is ordered %d\n", pancakeStackOrdered(pancakeStack));
  while (pancakeStack != NULL) {
      Pancake* next = pancakeStack->next;
      free(pancakeStack);
      pancakeStack = next;
  }
  return 0;
}
