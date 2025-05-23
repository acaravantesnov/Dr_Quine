#include <stdio.h>

void helper();

/*
* Comment outside main
*/

int main()
{
// Comment inside main
helper();
return 0;
}

void helper()
{
const char *src =
"#include <stdio.h>%c%cvoid helper();%c%c/*%c* Comment outside main%c*/%c%cint main()%c{%c// Comment inside main%chelper();%creturn 0;%c}%c%cvoid helper()%c{%cconst char *src =%c%c%s%c;%cprintf(src, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, src, 34, 10, 10);%c}";
printf(src, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, src, 34, 10, 10);
}