/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <assert.h>
#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    // Implement DFS
    // Hint: You can use print_node, print_tree and/or print_stack.

    // Allokerer plads til en ny stack.
    stack *newStack = (stack *)malloc(sizeof(stack));
    // Indsætter rooten i stacken, så stacken ikke er tom.
    newStack->node = root;
    newStack->next = NULL;

    // Kører igennem træeet, så længe min stack ikke er tom.
    // Stacken skal gerne først være tom, når det sidste tal er printet.
    while (!isEmpty(newStack)) {
        // Definerer currentnode til at være toppen af stacken newStack
        node *currentNode = top(newStack);

        // Så popper jeg det øverste element i stacken.
        newStack = pop(newStack);

        // Hvis currentNode har et right child, så pusher jeg den til stacken.
        // Her er det vigtigt, at right child pushes først. Ellers bliver
        // rækkefølgen ikke rigtig.
        if (currentNode->rchild != NULL) {
            newStack = push(newStack, currentNode->rchild);
        }
        // Hvis currentNode har et left child, så pusher jeg den til stacken.
        if (currentNode->lchild != NULL) {
            newStack = push(newStack, currentNode->lchild);
        }
        // Printer currentNode inden loopet kører igen.
        print_node(currentNode);
    }
    return;
}

node *make_node(int num, node *left, node *right) {
    // Allokerer plads og gemmer adressen i pointeren newNode.
    node *newNode = malloc(sizeof(node));

    // Gemmer alt indholdet på den nye til noden, på den allokerede plads.
    newNode->num = num;
    newNode->visited = false;
    newNode->lchild = left;
    newNode->rchild = right;

    // Returner newNode, så pointeren nu indeholder det rigtige data.
    return newNode;
}

void free_node(node *p) {
    // Asserter først at p ikke er NULL.
    if (p == NULL) {
        return;
    }
    // Derefter freer jeg først venstre, så højre barn og til sidst noden selv.
    free_node(p->lchild);
    free_node(p->rchild);
    free(p);
    return;
}

void print_node(node *p) {
    if (p == NULL)
        printf("NULL\n");
    else
        printf("%d, ", p->num);
}

void print_tree(node *p, int depth) {
    for (int i = 0; i < depth; i = i + 1) printf(" ");
    printf("| ");

    if (p == NULL)
        printf("NULL\n");
    else
        printf("[%d]\n", p->num);

    if (p->lchild) {
        print_tree(p->lchild, depth + 1);
    }

    if (p->rchild) print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) {
    stack *newStack = (stack *)malloc(sizeof(stack));
    newStack->next = topp;
    newStack->node = node;
    return newStack;
}

bool isEmpty(stack *topp) {
    if (topp == NULL) {
        return true;
    } else {
        return false;
    }
}

node *top(stack *topp) { return topp->node; }

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) {
    assert(!isEmpty(topp));
    stack *newStack = topp->next;
    free(topp);
    return newStack;
}

void print_stack(stack *topp) {
    struct stack *temp = topp;

    while (temp != NULL) {
        print_node(temp->node);
        printf("\n");

        temp = temp->next;
    }

    printf("====\n");

    return;
}
