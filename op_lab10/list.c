#include "books.h"

struct books* add_book(struct books* head, const char* author, const char* book_name, int year, int pages, double price) {
    struct books* newNode = (struct books*)malloc(sizeof(struct books));
    if (!newNode) {
        printf("Помилка виділення пам’яті\n");
        return head;
    }

    strcpy(newNode->author, author);
    strcpy(newNode->book_name, book_name);
    newNode->year = year;
    newNode->pages = pages;
    newNode->price = price;
    newNode->next = NULL;

    if (!head || strcmp(newNode->author, head->author) < 0) {
        newNode->next = head;
        return newNode;
    }

    struct books* current = head;
    while (current->next && strcmp(newNode->author, current->next->author) > 0) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct books* delete_books_by_price(struct books* head, double min_price) {
    struct books* current = head;
    struct books* prev = NULL;

    while (current) {
        if (current->price < min_price) {
            struct books* temp = current;
            current = current->next;
            if (!prev) {
                head = current;
            } else {
                prev->next = current;
            }
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}

void free_books(struct books* head) {
    struct books* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
