#ifndef _CONTACT_H_
#define _CONTACT_H_

/*
  Un contact représente une association {nom, numéro}.
*/
struct contact {
    const char* name;
    const char* num;
};

/* 
  Structure de données décrivant une liste chainée 
*/
struct cellule {
    struct contact* contact;
    struct cellule* next;
};

/* TOUT DOUX: à compléter */
/* Profitez de cette période sombre pour braver les interdits et rétablir le contact. */

/*
  Insère un nouveau contact dans la liste de contact _cptr_ construit à partir des nom et
  numéro passés en paramètre.
  La liste de contact _cptr_ n'est pas vide, n'est pas le pointeur NULL.
  Si il existait déjà un contact du même nom, son numéro est remplacé et la fonction
  retourne une copie de l'ancien numéro. Sinon, la fonction retourne NULL.
*/
extern char* contact_insert(struct cellule** cptr, const char* name, const char* num);

/*
  Retourne le numéro associé au nom _name_ dans la liste de contact _cptr_
  Si aucun contact ne correspond, retourne NULL.
*/
extern const char* contact_search(struct cellule* cptr, const char* name);

/*
  Supprime le contact de nom _name_ de la liste de contact _cptr_
  Si aucun contact ne correspond, ne fait rien.
*/
extern void contact_delete(struct cellule** cptr, const char* name);

/*
  Libère la mémoire associée à la liste de contact _cptr_.
*/
extern void contact_free(struct cellule* cptr);

/*
  Affiche sur la sortie standard le contenu de la liste de contact _cptr_.
*/
extern void contact_print(struct cellule* cptr);

#endif /* _CONTACT_H_ */
