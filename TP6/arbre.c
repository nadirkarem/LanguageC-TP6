#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main() {
    // Création de l'arbre vide
    TreeNode* arbre = NULL;

    // Tableau des nombres à trier
    int nombres[] = {101, 8, 14, 129, 4, 99, 13, 55};
    int taille = sizeof(nombres) / sizeof(nombres[0]);

    // Insertion des nombres dans l'arbre
    for (int i = 0; i < taille; i++) {
        arbre = insert(arbre, nombres[i]);
    }


    // Affichage des nombres triés
    printf("Nombres triés : \n ");
    inOrder(arbre);
    printf("\n");

    // Suppression d'un nœud
    deleteNode(arbre, 55);
    printf("Nombres triés après suppression du 55 : \n ");
    inOrder(arbre);
    printf("\n");


    // Libération de la mémoire allouée pour l'arbre
    freeTree(arbre);

    return 0;
}

TreeNode* createNode(int valeur) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->data = valeur;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Fonction récursive pour insérer une valeur dans l'arbre binaire de recherche
TreeNode* insert(TreeNode* racine, int valeur) {
    // Cas de base : si le nœud est NULL, créer un nouveau nœud avec la valeur
    if (racine == NULL) {
        return createNode(valeur);
    }

    // Si la valeur est inférieure, insérer à gauche
    if (valeur < racine->data) {
        racine->left = insert(racine->left, valeur);
    }
    // Si la valeur est supérieure ou égale, insérer à droite
    else {
        racine->right = insert(racine->right, valeur);
    }

    // Retourner le nœud modifié
    return racine;
}

void inOrder(TreeNode* racine) {
    if (racine != NULL) {
        // Parcours du sous-arbre gauche
        inOrder(racine->left);

        // Affichage de la valeur du nœud courant
        printf("%d ", racine->data);

        // Parcours du sous-arbre droit
        inOrder(racine->right);
    }
}

void freeTree(TreeNode* racine) {
    if (racine != NULL) {
        freeTree(racine->left);
        freeTree(racine->right);
        free(racine);
    }
}

TreeNode* deleteNode(TreeNode* racine, int valeur) {
    // Cas de base : si le nœud est NULL, la valeur n'est pas présente
    if (racine == NULL) {
        return racine;
    }

    // Recherche de la valeur dans le sous-arbre gauche
    if (valeur < racine->data) {
        racine->left = deleteNode(racine->left, valeur);
    }
    // Recherche de la valeur dans le sous-arbre droit
    else if (valeur > racine->data) {
        racine->right = deleteNode(racine->right, valeur);
    }
    // La valeur a été trouvée
    else {
        // Cas 1 : le nœud n'a pas d'enfants
        if (racine->left == NULL && racine->right == NULL) {
            free(racine);
            racine = NULL;
        }
        // Cas 2 : le nœud a un enfant
        else if (racine->left == NULL) {
            TreeNode* temp = racine;
            racine = racine->right;
            free(temp);
        } else if (racine->right == NULL) {
            TreeNode* temp = racine;
            racine = racine->left;
            free(temp);
        }
        // Cas 3 : le nœud a deux enfants
        else {
            TreeNode* temp = findMin(racine->right);
            racine->data = temp->data;
            racine->right = deleteNode(racine->right, temp->data);
        }
    }
    return racine;
}

TreeNode* findMin(TreeNode* racine) {
    if (racine == NULL) {
        return NULL;
    } else if (racine->left != NULL) {
        return findMin(racine->left);
    }
    return racine;
}