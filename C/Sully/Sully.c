#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
int i = 5;
const char *src = "#include <stdio.h>%c#include <fcntl.h>%c#include <stdlib.h>%c#include <unistd.h>%c%cint main()%c{%cint i = %i;%cconst char *src = %c%s%c;%c%c#ifndef CHILD_RUN%cint fd = open(%cSully_5.c%c, O_WRONLY | O_CREAT, 0644);%cdprintf(fd, src, 10, 10, 10, 10, 10, 10, 10, i, 10, 34, src, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10);%cclose(fd);%cchar cmd[100];%csprintf(cmd, %cclang -Wall -Wextra -Werror -D CHILD_RUN Sully_5.c -o Sully_5 ; ./Sully_5%c);%csystem(cmd);%c#else%cif ((i - 1) >= 0)%c{%cchar filename[22];%csprintf(filename, %cSully_%%d.c%c, i - 1);%cint fd = open(filename, O_WRONLY | O_CREAT, 0644);%cdprintf(fd, src, 10, 10, 10, 10, 10, 10, 10, i - 1, 10, 34, src, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10);%cclose(fd);%cchar cmd[100];%csprintf(cmd, %cclang -Wall -Wextra -Werror -D CHILD_RUN Sully_%%i.c -o Sully_%%i ; ./Sully_%%i%c, i - 1, i - 1, i - 1);%csystem(cmd);%c}%c#endif%c}";

#ifndef CHILD_RUN
int fd = open("Sully_5.c", O_WRONLY | O_CREAT, 0644);
dprintf(fd, src, 10, 10, 10, 10, 10, 10, 10, i, 10, 34, src, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10);
close(fd);
char cmd[100];
sprintf(cmd, "clang -Wall -Wextra -Werror -D CHILD_RUN Sully_5.c -o Sully_5 ; ./Sully_5");
system(cmd);
#else
if ((i - 1) >= 0)
{
char filename[22];
sprintf(filename, "Sully_%d.c", i - 1);
int fd = open(filename, O_WRONLY | O_CREAT, 0644);
dprintf(fd, src, 10, 10, 10, 10, 10, 10, 10, i - 1, 10, 34, src, 34, 10, 10, 10, 34, 34, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, 34, 10, 10, 10, 10);
close(fd);
char cmd[100];
sprintf(cmd, "clang -Wall -Wextra -Werror -D CHILD_RUN Sully_%i.c -o Sully_%i ; ./Sully_%i", i - 1, i - 1, i - 1);
system(cmd);
}
#endif
}