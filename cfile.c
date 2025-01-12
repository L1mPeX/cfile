#include <stdio.h>
#include <stdlib.h>
#include <magic.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <file> [custom_magic_file]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *custom_magic_file = (argc == 3) ? argv[2] : NULL;

    magic_t magic;

    // Инициализация magic
    magic = magic_open(MAGIC_NONE);
    if (magic == NULL) {
        fprintf(stderr, "Failed to initialize libmagic\n");
        return 1;
    }

    // Загрузка базы данных типов
    if (magic_load(magic, custom_magic_file) != 0) {
        fprintf(stderr, "Error loading magic database: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }

    // Получение типа файла
    const char *file_type = magic_file(magic, filename);
    if (file_type == NULL) {
        fprintf(stderr, "Error determining file type: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }

    printf("File type: %s\n", file_type);

    // Очистка ресурсов
    magic_close(magic);
    return 0;
}
