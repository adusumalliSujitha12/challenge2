#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_date_t {
    uint8_t date,      
    uint8_t month,      
    uint16_t year,     
};

enum status_t{
    success,
};
struct my_date_t convertStringToDate(const char* dateString) {
    struct my_date_t date;
    char* token;
    char* copy = strdup(dateString);
    token = strtok(copy, "/");
    date.day = atoi(token);

    token = strtok(NULL, "/");
    date.month = atoi(token);

    token = strtok(NULL, "/");
    date.year = atoi(token);

    free(copy);
    return date;
}

int main() {
    const char* dateStr[15];// = "08/06/2023";
    scanf("%s",&dateStr);
    struct my_date_t convertedDate = convertStringToDate(dateStr);

    printf("Day: %d\n", convertedDate.day);
    printf("Month: %d\n", convertedDate.month);
    printf("Year: %d\n", convertedDate.year);

    return 0;
}