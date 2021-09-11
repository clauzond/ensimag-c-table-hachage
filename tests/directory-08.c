/*
  Test du module directory.

  Teste l'agrandissement de directory avec noms identiques
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <directory.h>

int main(void) {
    struct dir* dir = dir_create(10);
    dir_insert(dir, "Colonel Moutarde", "06789435351");
    dir_insert(dir, "Caporal Ketchup", "0678346533");
    dir_insert(dir, "Sergent Mayo", "06723236533");
    dir_insert(dir, "Adjudant Barbecue", "01723236533");
    dir_insert(dir, "Capitaine Flamme", "0666420123");
    dir_insert(dir, "Jean Bonbeurre", "01723236533");
    dir_insert(dir, "Eddy", "0100000000");
    dir_insert(dir, "Addy", "0200000000");
    dir_print(dir);
    printf("\n------------------\n\n");
    assert((dir->contact_number) > 7);
    assert((dir->array_len) > 10);
    dir_insert(dir, "Oddy", "0300000000");
    dir_insert(dir, "Iddy", "0400000000");
    dir_insert(dir, "Uddy", "0500000000");
    dir_insert(dir, "Juddy", "0600000000");
    dir_insert(dir, "Cappy", "0700000000");
    dir_insert(dir, "Nappy", "0800000000");
    dir_insert(dir, "Tappy", "0900000000");
    char* r1 = dir_insert(dir, "Tappy", "0010000000");
    char* r2 = dir_insert(dir, "Tappy", "0020000000");
    char* r3 = dir_insert(dir, "Tappy", "0030000000");
    char* r4 = dir_insert(dir, "Tappy", "0040000000");
    char* r5 = dir_insert(dir, "Tappy", "0050000000");
    dir_insert(dir, "Joey", "0123456789");
    dir_insert(dir, "Koey", "0120000009");
    const char* numero = dir_lookup_num(dir, "Joey");
    const char* numero2 = dir_lookup_num(dir, "Jacques Itchane");
    assert(strcmp(numero, "0123456789") == 0);
    assert((numero2 == NULL));
    assert((dir->contact_number) > 16);
    assert((dir->array_len) > 20);
    dir_print(dir);
    dir_free(dir);
    free(r1); // pour valgrind
    free(r2);
    free(r3);
    free(r4);
    free(r5);

    return EXIT_SUCCESS;
}
