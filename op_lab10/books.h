#ifndef BOOKS_H
#define BOOKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct books {
    char author[50];
    char book_name[50];
    int year;
    int pages;
    double price;
    struct books* next;
};

struct books* add_book(struct books* head, const char* author, const char* book_name, int year, int pages, double price);
struct books* delete_books_by_price(struct books* head, double min_price);
void free_books(struct books* head);

struct books* read_books();
void write_books(struct books* head);
void print_books(struct books* head);

#endif
