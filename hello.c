// C version to look at Assembly
#include <unistd.h>
#include <stdlib.h>

void _start() {
write(1,"Hello World!", 12);
exit(0);
}
