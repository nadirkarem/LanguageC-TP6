#ifndef ARBRE_H
#define ARBRE_H

// Définition de la structure ListNode
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// Prototypes des fonctions
TreeNode* createNode(int valeur);
void inOrder(TreeNode* racine);
TreeNode* insert(TreeNode* racine, int valeur);
void freeTree(TreeNode* racine);
TreeNode* findMin(TreeNode* racine);
TreeNode* deleteNode(TreeNode* racine, int valeur);
TreeNode* affichage_tree(TreeNode* racine, int espace) ;


#endif // ARBRE_H