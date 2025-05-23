#include <stdio.h>
#include <fcntl.h>

#define OPEN(file_path) open(file_path, O_WRONLY | O_CREAT, 0644)
#define FILE_TEXT "#include <stdio.h>%c#include <fcntl.h>%c%c#define OPEN(file_path) open(file_path, O_WRONLY | O_CREAT, 0644)%c#define FILE_TEXT %c%s%c%c#define FT(x)int main(){dprintf(OPEN(%cGrace_kid.c%c), x, 10, 10, 10, 10, 34, x, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10);}%c%c/*%c    Comment%c*/%cFT(FILE_TEXT)%c%c"
#define FT(x)int main(){dprintf(OPEN("Grace_kid.c"), x, 10, 10, 10, 10, 34, x, 34, 10, 34, 34, 10, 10, 10, 10, 10, 10, 10);}

/*
    Comment
*/
FT(FILE_TEXT)

