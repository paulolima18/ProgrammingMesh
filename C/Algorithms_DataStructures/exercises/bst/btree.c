#include <stdio.h>
#include <stdlib.h>

/* Binary Search Tree [BST] */

typedef struct btree {
    int value;
    struct btree *left, *right;
} Node, *BTree;

/* Number of nodes in the given tree */
int size(BTree tree) {
    if(tree == NULL) return 0;
    return 1 + size(tree -> left) + size(tree -> right);
}

int height(BTree tree) {
    if(tree == NULL) return 0;
    int x=0,y=x;
    x = 1 + height(tree->left);
    y = 1 + height(tree->right);
    return ( x > y ? x : y);
}

BTree add(BTree tree, int x) {
    BTree *aux = &tree;
    while((*aux)!=NULL) {
        if (x < (*aux)->value)
            aux = &((*aux)->left);
        else
            aux = &((*aux)->right);
    }
    (*aux) = malloc(sizeof(struct btree));
    (*aux) -> value = x;
    (*aux) -> left = (*aux) -> right = NULL;
    return tree;
}

int search(BTree tree, int x) {
    int r = 0;
    if(tree != NULL) {
        if(tree->value == x)
            r = 1;
        else if(tree->value > x)
            r = search(tree -> left, x);
        else
            r = search(tree -> right, x);
    }
    return r;
}

int max(BTree tree) {
    int val=0;
    if(tree != NULL){
        val = tree->value;
        if(tree->right != NULL)
            val = max(tree->right);
    }
    return val;
}

// int max(BTree tree) {
//     int val=0,aux;
//     if(tree != NULL){
//         val = tree->value;
//         if(val < (aux=max(tree->left)))
//             val = aux;
//         else if(val < (aux=max(tree->right)))
//             val = aux;
//     }
//     return val;
// }

int balanceada (BTree tree) {
    int left, right;
    if (tree) {
        left = height (tree->left);
        right = height (tree->right);
        return ((abs (left-right) <= 1) && balanceada (tree->left) && balanceada (tree->right));
    }
    else
        return 1;
}

int balanced_aux(BTree tree, int *p) {
    int l, r;
    if(tree) {
        l = height(tree->left);
        r = height(tree->right);
        return (abs(l-r)<=1);
    }
    return 1;
}

int balanced(BTree tree) {
    int p;
    return balanced_aux(tree, &p);
}

void print_tree_df(BTree tree) {
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
    BTree tree = malloc(sizeof(BTree));
    Node first;
    Node second;
    Node third;
    Node fourth;
    Node five;

    five.left = NULL;
    five.right = NULL;
    five.value = 4;

    fourth.left = NULL;
    fourth.right = NULL;
    fourth.value = 1;

    second.left = &fourth;
    second.right = NULL;
    third.left = NULL;
    third.right = NULL;

    *tree = first;
    tree -> left = &second;
    tree -> right = &third;
    tree -> value = 3;
    tree -> left -> value = 2;
    tree -> right -> value = 4;

    tree = add(tree, 5);
    int k = 3;
    print_tree_df(tree);
    printf("Function[Balanced] | Balanced? : %d\n",balanced(tree));
    printf("Function[Height]   | Tree height: %d\n",height(tree));
    printf("Function[Search]   | Found %d: %d\n", k, search(tree,k));
    printf("Function[Size]     | Tree size: %d\n",size(tree));
    printf("Function[Max]      | Max is : %d\n",max(tree));
    return 0;
}
