#ifndef BOOK_H
#define BOOK_H

typedef struct book
{
    char title[50];
    char author[50];
    int year;
    int id;
    struct book *next;
} book_t, *book_ptr_t;

#endif // BOOK_H