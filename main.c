#include <stdio.h>
#include "livro.h"

int main() {
    sentLivros sentL;
    sentL.first = NULL;
    sentL.last  = NULL;

    insereListaLivros(&sentL);
    

    return 0;
}