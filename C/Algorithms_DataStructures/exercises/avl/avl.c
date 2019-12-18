#include <stdio.h>
#include <stdlib.h>

#define BAL 0
#define RIGHT 1
#define LEFT 2

typedef struct avlTree{
    int value, bal;
    struct avlTree *left, *right;
}AVLNode, *AVLTree;

/* Cool website: https://www.cs.usfca.edu/~galles/visualization/AVLtree.html */

int heightAVL(AVLTree tree) {
    int result=0;
    if(tree != NULL) {
        if(tree -> bal == RIGHT)
            result += 1 + heightAVL(tree->right);
        else
            result += 1 + heightAVL(tree->left);
    }
    return result;
}

AVLTree rotateLeft(AVLTree tree) {
    AVLTree b = tree -> right;
    tree -> right = b -> left;
    b -> left = tree;
    return b;
}

AVLTree rotateRight(AVLTree tree) {
    AVLTree b = tree -> left;
    tree -> left = b -> right;
    b -> right = tree;
    return b;
}

void print_tree_df(AVLTree tree) {
    if(tree != NULL) {
        printf("%d\n",tree->value);
        if(tree -> left != NULL) {
            printf("left: ");
            print_tree_df(tree->left);
        }
        if(tree -> right != NULL) {
            printf("right: ");
            print_tree_df(tree->right);
        }
    }
}

int main() {
    AVLTree tree;

    AVLNode left_1;
    AVLNode left_2;

    left_1.value = 2;
    left_1.bal = BAL;
    left_1.left = &left_2;
    left_1.right = NULL;

    left_2.value = 3;
    left_2.bal = BAL;
    left_2.left = NULL;
    left_2.right = NULL;

    tree = malloc(sizeof(struct avlTree));

    tree -> value = 1;
    tree -> bal = BAL;
    tree -> left = &left_1;
    tree -> right = NULL;

    /* Balance tree */
    tree = rotateRight(tree);
    print_tree_df(tree);
    printf("AVL height: %d\n", heightAVL(tree));
    return 0;
}
