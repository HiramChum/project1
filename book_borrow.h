#ifndef BOOK_BORROW_H
#define BOOK_BORROW_H

typedef struct book_borrow
{
    int id_borrow;
    int own_book;
    struct book_borrow* next_book_borrow;
    char title1[50];
    char title2[50];
    char title3[50];
    char title4[50];
    char title5[50];
}book_borrow_t,*book_borrow_ptr_t;

#endif