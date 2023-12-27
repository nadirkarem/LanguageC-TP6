#ifndef NODE_H
#define NODE_H

// Définition de la structure ListNode
typedef struct ListNode {
    int valeur;                // La valeur du nœud
    struct ListNode* suivant;  // Pointeur vers le prochain nœud
} ListNode;

// Prototypes des fonctions
ListNode* creerNoeud(int valeur);
ListNode* insert_end(ListNode* tete, int valeur);  // Modification du prototype
void free_List(ListNode* tete);
void afficherListe(ListNode* tete);
ListNode* insertBeginning(ListNode* tete, int valeur);
ListNode* insertMiddle(ListNode* tete, int valeur, ListNode* Node_prec);
ListNode* deleteNode(ListNode* tete, int valeur);
ListNode* searchNode(ListNode* tete, int valeur);
ListNode* sorterList(ListNode* tete);

#endif // NODE_H
