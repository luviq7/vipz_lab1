#include "books.h"

int main() {
    struct books* head = read_books();

    printf("Список після зчитування:\n");
    print_books(head);
    printf("\n");

    head = add_book(head, "NEW_AUTHOR", "NEW_BOOK", 9999, 999, 999.0);

    printf("Список після додавання нової книги:\n");
    print_books(head);
    printf("\n");

    head = delete_books_by_price(head, 5.0);

    printf("Список після видалення книг з ціною < 5 грн:\n");
    print_books(head);
    printf("\n");
    write_books(head);
    free_books(head);

}
