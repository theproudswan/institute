#include <stdio.h>

unsigned str_len (const char *str);
unsigned IsCorrect (const char *str);

int main (int argc, char *argv[]){
    unsigned error = 0;
    if ((argc < 2) || (argc > 9)){
        printf("Ошибка. Недопутимое количество элементов в массиве.\nДолжно быть от 1 до 8 включительно.\nВаше количество: %i\n", argc - 1);
        error = 1;
    }
    if(error){
        return 0;
    }
    char *tmp;
    for(int i = 1; i<argc; ++i){
        if(IsCorrect(argv[i])){
            printf("\nАргумент <%s> не удовлетворяет условию\nАргумент содержит символы, не встречающиеся в английском алфавите и не являющиеся арабскими цифрами\n", argv[i]);
            error = 1;
        }
    }
    if(error){
        return 0;
    }
    unsigned i, j;
    for (i = 1; i<argc; i++){
        for (j = 1; j<argc-1; j++){
            if (str_len(argv[j])>str_len(argv[j + 1])){
                tmp = argv[j];
                argv[j] = argv[j + 1];
                argv[j + 1] = tmp;
            }
        }
    }
    puts("Отсортированный массив:");
    for(i = 1; i<argc; ++i){
        printf("%s\n", argv[i]);
    }
    return 0;
}

unsigned str_len (const char *str){
    for (const char* c = str;;c++){
        if (!*c){
            return c-str;
        } 
    } 
}

unsigned IsCorrect (const char *str){
    for(unsigned i = 0; i<str_len(str); ++i){
         if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
             ;
         } else {
             return 1;
         }
    }
    return 0;
}