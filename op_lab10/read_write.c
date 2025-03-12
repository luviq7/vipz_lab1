#include "books.h"

struct books* read_books() {
    struct books* head = NULL;
    FILE* in = fopen("in.txt", "r");

    if (!in) {
        printf("Помилка відкриття файлу in.txt\n");
        return NULL;
    }

    char author[50], book_name[50];
    int year, pages;
    double price;

    while (fscanf(in, " \"%[^\"]\" \"%[^\"]\" %d %d %lf", author, book_name, &year, &pages, &price) == 5) {
        head = add_book(head, author, book_name, year, pages, price);
    }
    fclose(in);
    return head;
}

void write_books(struct books* head) {
    FILE* out = fopen("out.txt", "w");
    if (!out) {
        printf("Помилка відкриття файлу out.txt\n");
        return;
    }

    struct books* current = head;
    while (current) {
        fprintf(out, "\"%s\" \"%s\" %d %d %.2lf\n", current->author, current->book_name, current->year, current->pages, current->price);
        current = current->next;
    }
    fclose(out);
}

void print_books(struct books* head) {
    struct books* current = head;
    while (current) {
        printf("\"%s\" \"%s\" %d %d %.2lf\n", current->author, current->book_name, current->year, current->pages, current->price);
        current = current->next;
    }
}
