/*
 * Search an expression using DFS.
 */

#include "dfs.h"

#include <stdbool.h> /* bool, true, false */
#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */

void DFT(node *root) {
    // Implement DFS
    // Hint: You can use print_node, print_tree and/or print_stack.

    // I denne opgave traverserer jeg igennem træet ved hjælp af recursion.
    // Jeg bruger kun make_node og print_node. Derfor har jeg kun lavet de
    // funktioner.

    // Basecasen er at root er null. Altså at vi er nået til ud til enden af en
    // gren. Hvis jeg når derud, så skal jeg stoppe og derfor returner jeg.
    if (root == NULL) {
        return;
    }
    // Hvis ikke jeg returner, så kommer jeg herned. Det betyder, at jeg som
    // mimum står på et af de yderste tal. Derfor starter jeg med at printe.
    print_node(root);

    // Går videre mod venstre child.
    DFT(root->lchild);
    // Når der ikke er flere childs mod venstre, så går jeg mod højre.
    DFT(root->rchild);
}

node *make_node(int num, node *left, node *right) {
    // Allokerer plads og gemmer adressen i pointeren newNode.
    node *newNode = (node *)malloc(sizeof(node));

    // Gemmer alt indholdet på den nye til noden, på den allokerede plads.
    newNode->num = num;
    newNode->visited = false;
    newNode->lchild = left;
    newNode->rchild = right;

    // Returner newNode, så pointeren nu indeholder det rigtige data.
    return newNode;
}

void free_node(node *p) {}

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

stack *push(stack *topp, node *node) { return 0; }

bool isEmpty(stack *topp) { return false; }

node *top(stack *topp) { return 0; }

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) { return 0; }

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
