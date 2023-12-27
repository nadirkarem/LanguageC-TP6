#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    // Création de la racine de la liste chaînée
    ListNode* racine = malloc(sizeof(ListNode));
    racine->valeur = 0;
    racine->suivant = NULL;

    // Insertion d'éléments à la fin de la liste
    racine = insert_end(racine, 1);
    racine = insert_end(racine, 99);
    racine = insert_end(racine, 11);

    // Affichage de la liste chaînée
    printf("On a la liste suivante\n");  
    afficherListe(racine);
    printf("\n");  
    

    // Insertion d'un élément au début de la liste
    printf("On ajoute un élément au début de la liste\n");
    racine = insertBeginning(racine, -1);
    afficherListe(racine);
    printf("\n");  

    // Insertion d'un élément à l'intérieur de la liste
    printf("On ajoute un élément à l'intérieur de la liste. On l'insère après les 3ème élément de la liste\n");
    racine = insertMiddle(racine, 42, racine->suivant->suivant->suivant);
    afficherListe(racine);
    printf("\n");  

    // Suppression d'un élément de la liste
    printf("On supprime un élément de la liste. On supprime l'élément avec la valeur 0\n");
    racine = deleteNode(racine, 0);
    afficherListe(racine);
    printf("\n");  // Saut de ligne

    // Recherche d'un élément dans la liste
    printf("On recherche un élément dans la liste. On recherche l'élément avec la valeur 42\n");
    ListNode* node = searchNode(racine, 42);
    printf("\n");  

    // Tri de la liste
    printf("On trie la liste:\n");
    racine = sorterList(racine);
    afficherListe(racine);

    // Libération de la mémoire allouée pour la liste chaînée
    free_List(racine);
    printf("\n");
    printf("\n");
    return 0;
}

// Fonction pour créer un nouveau nœud
ListNode* creerNoeud(int valeur) {
    ListNode* nouveauNode = malloc(sizeof(ListNode));
    if (nouveauNode != NULL) {
        nouveauNode->valeur = valeur;
        nouveauNode->suivant = NULL;
    }
    return nouveauNode;
}

// Fonction pour insérer un élément à la fin de la liste
ListNode* insert_end(ListNode* tete, int valeur) {
    ListNode* new_node = creerNoeud(valeur);

    if (tete == NULL) {
        return new_node;  // Si la liste est vide, le nouveau nœud devient la tête
    } else {
        ListNode* node_courant = tete; // Parcourir la liste jusqu'à la fin sans changer tete pour pouvoir return tete
        while (node_courant->suivant != NULL) {
            node_courant = node_courant->suivant;
        }
        node_courant->suivant = new_node;
        return tete;
    }
}

// Fonction pour afficher une liste chaînée
void afficherListe(ListNode* tete) {
    while (tete != NULL) {
        printf("Node: %d\n", tete->valeur);
        tete = tete->suivant;
    }
}

// Fonction pour libérer la mémoire allouée pour une liste chaînée
void free_List(ListNode* tete) {
    while (tete != NULL) {
        ListNode* temp = tete;
        tete = tete->suivant;
        free(temp);
    }
}

// Fonction pour insérer un élément au début de la liste
ListNode* insertBeginning(ListNode* tete, int valeur) {
    ListNode* new_node = creerNoeud(valeur);
    if (new_node != NULL) {
        new_node->suivant = tete;
        return new_node;  // Le nouveau nœud devient la nouvelle tête
    } else {
        // Gestion de l'échec de l'allocation mémoire
        fprintf(stderr, "Erreur d'allocation mémoire pour le nouveau nœud.\n");
        exit(EXIT_FAILURE);
    }
}

// Fonction pour insérer un élément à l'intérieur de la liste après un élément donné
ListNode* insertMiddle(ListNode* tete, int valeur, ListNode* Node_prec) {
    ListNode* new_node = creerNoeud(valeur);
    if (new_node != NULL) {
        ListNode* node_courant = tete;

        // Parcourir la liste jusqu'à trouver l'élément après lequel insérer
        while (node_courant != NULL && node_courant->suivant != Node_prec) {
            node_courant = node_courant->suivant;
        }

        // Si l'élément après lequel insérer est trouvé
        if (node_courant->suivant == Node_prec) {
            ListNode* temp = node_courant->suivant;
            node_courant->suivant = new_node;
            new_node->suivant = temp;
        } else {
            // L'élément après lequel insérer n'est pas présent dans la liste
            fprintf(stderr, "L'élément recherché n'a pas été trouvé dans la liste.\n");
            free(new_node);
        }

        return tete;
    } else {
        // Gestion de l'échec de l'allocation mémoire
        fprintf(stderr, "Erreur d'allocation mémoire pour le nouveau nœud.\n");
        exit(EXIT_FAILURE);
    }

    
}

// Fonction pour effacer un nœud basé sur sa valeur
ListNode* deleteNode(ListNode* tete, int valeur) {
    ListNode* node_courant = tete;
    ListNode* previous = NULL;

    // Parcourir la liste jusqu'à trouver le nœud à supprimer
    while (node_courant != NULL && node_courant->valeur != valeur) {
        previous = node_courant;
        node_courant = node_courant->suivant;
    }

    // Si le nœud à supprimer est trouvé
    if (node_courant != NULL) {
        // Mettre à jour les liens pour sauter le nœud à supprimer
        if (previous != NULL) {
            previous->suivant = node_courant->suivant;
        } else {
            // Si le nœud à supprimer est la tête de la liste
            tete = node_courant->suivant;
        }

        // Libérer la mémoire du nœud supprimé
        free(node_courant);
    } else {
        // Le nœud à supprimer n'est pas présent dans la liste
        fprintf(stderr, "L'élément avec la valeur %d n'a pas été trouvé dans la liste.\n", valeur);
    }

    return tete;
}

// Nouvelle fonction pour trouver un nœud basé sur sa valeur
ListNode* searchNode(ListNode* tete, int valeur) {
    ListNode* node_courant = tete;
    int count = 0;
    // Parcourir la liste jusqu'à trouver le nœud avec la valeur recherchée
    while (node_courant != NULL && node_courant->valeur != valeur) {
        count = count + 1;
        node_courant = node_courant->suivant;
    }

    if (node_courant->valeur == valeur) {
        printf("Node: %d\n", node_courant->valeur);
        printf("Position: %d (0 étant la tête de la liste)\n", count);
    } else {
        printf("L'élément recherché n'a pas été trouvé dans la liste.\n");
    }

    return node_courant;
}

ListNode* sorterList(ListNode* tete) {
    if (tete == NULL || tete->suivant == NULL) {
        // La liste est déjà triée si elle est vide ou a un seul élément
        return tete;
    }

    ListNode* node_fictif = creerNoeud(0);
    node_fictif->suivant = tete;
    ListNode* temp;

    int swapped;

    do {
        swapped = 0;
        
        ListNode* node_prec = node_fictif;
        ListNode* node_courant = node_fictif->suivant;
        ListNode* next_node = node_courant->suivant;

        while (next_node != NULL) {
            
            if (node_courant->valeur > next_node->valeur) {
                // Échange de valeurs
                node_prec->suivant = next_node;
                temp = next_node->suivant;
                next_node->suivant = node_courant;
                node_courant->suivant = temp;
                node_prec = next_node;
                
                swapped = 1;

                
            } else {
                // Aucun échange nécessaire, passez au nœud suivant
                node_prec = node_prec->suivant;
                node_courant = node_courant->suivant;
            }

            next_node = node_courant->suivant;
        }

    } while (swapped);

    ListNode* new_tete = node_fictif->suivant;
    free(node_fictif);

    return new_tete;
}
