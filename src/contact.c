#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "contact.h"

/*
Spécification du module LIBRE
--> il faut identifier les fonctions utiles pour la construction d'un annuaire de contacts
--> il faut faire ses propres tests
*/

/*
  Un contact représente une association {nom, numéro}.
*/
struct contact;

/*
  Structure de données décrivant une liste chainée
*/
struct cellule;

/*
  Insère un nouveau contact dans la liste de contact _cptr_ construit à partir des nom et
  numéro passés en paramètre.
  La liste de contact _cptr_ n'est pas vide, n'est pas le pointeur NULL.
  Si il existait déjà un contact du même nom, son numéro est remplacé et la fonction
  retourne une copie de l'ancien numéro. Sinon, la fonction retourne NULL.
*/
char* contact_insert(struct cellule** cptr, const char* name, const char* num) {
    struct cellule sentinelle = {NULL, *cptr};
    struct cellule* sent = &sentinelle;
    while (sent->next != NULL) {
        sent = sent->next;
        if (strcmp(sent->contact->name, name) == 0) {
            char* ret = malloc(strlen(sent->contact->num) + 1); // on fait une copie de l'ancien numéro
            strcpy(ret, sent->contact->num);
            sent->contact->num = num;
            return ret;
        }
    }
    struct contact* cont = malloc(sizeof(struct contact)); // création du contact suivant
    cont->name = name;
    cont->num = num;
    struct cellule* cel = malloc(sizeof(struct cellule));
    cel->contact = cont;
    cel->next = NULL;
    sent->next = cel;
    *cptr = sentinelle.next; // on remplace le pointeur vers la cellule
    return NULL;
}

/*
  Retourne le numéro associé au nom _name_ dans la liste de contact _cptr_
  Si aucun contact ne correspond, retourne NULL.
*/
const char* contact_search(struct cellule* cptr, const char* name) {
    struct cellule sentinelle = {NULL, cptr};
    struct cellule* sent = &sentinelle;
    while (sent->next != NULL) {
        sent = sent->next;
        if (strcmp(sent->contact->name, name) == 0) {
            return sent->contact->num;
        }
    }
    return NULL;
}

/*
  Supprime le contact de nom _name_ de la liste de contact _cptr_
  Si aucun contact ne correspond, ne fait rien.
*/
void contact_delete(struct cellule** cptr, const char* name) {
    struct cellule sentinelle = {NULL, *cptr};
    struct cellule* sent = &sentinelle;
    while (sent->next != NULL) {
        if (strcmp(sent->next->contact->name, name) == 0) {
            struct cellule* to_delete = sent->next;
            sent->next = to_delete->next;
            *cptr = sentinelle.next; // on remplace le pointeur vers la cellule
            free(to_delete->contact);
            free(to_delete);
            return;
        }
        sent = sent->next;
    }
}


/*
  Libère la mémoire associée à la liste de contact _cptr_.
*/
void contact_free(struct cellule* cptr) {
    if (cptr == NULL) {
        return;
    }

    while (cptr->next != NULL) {
        struct cellule* to_delete = cptr->next;
        cptr->next = to_delete->next;
        free(to_delete->contact);
        free(to_delete);
    }
    free(cptr->contact);
    free(cptr);
}

/*
  Affiche sur la sortie standard le contenu de la liste de contact _cptr_.
*/
void contact_print(struct cellule* cptr) {
    if (cptr == NULL) {
        return;
    }
    while (cptr->next != NULL) {
        printf("%s (%s), ", cptr->contact->name, cptr->contact->num);
        cptr = cptr->next;
    }
    printf("%s (%s)\n", cptr->contact->name, cptr->contact->num);   
}