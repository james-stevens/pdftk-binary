#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CHROOT_DIR "/usr/local/chroot-pdftk"
#define BIN_RUN "/bin/pdftk"

int main(int argc,char * argv[])
{
int ret;

	if (chroot(CHROOT_DIR)) { perror("chroot:"); exit(1); }
	argv[0] = BIN_RUN;
	if (execv(BIN_RUN,argv)) { perror("exec"); exit(1); }
	return ret;
}
