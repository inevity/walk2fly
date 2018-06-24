//#include <chtbl.h>
#include "chtbl.h"
int main(void) {
    //CHTbl * htbl; because init have not process null htbl.
    //struct init
    CHTbl * htbl = (CHTbl *)malloc(sizeof(CHTbl));
    chtbl_init(htbl, 4,NULL,NULL,NULL);
    return 0;
}