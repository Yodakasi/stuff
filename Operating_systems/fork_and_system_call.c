#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int flag = 0;
void sighandler(int sig) {
	flag = 1;
	puts("sighandler");
}

void do_parent(int pid) {
	sleep(1);
	int ret = kill(pid, 30);
	if(ret == -1) {
		exit(0);
	}
	if(wait(0)<0)
		perror("wait");
}

void do_child() {
	if(signal(30, sighandler) == SIG_ERR) {
		exit(0);
	}
	pause();
	if(flag) {
		puts("flaga");
	}
}


int main() {
	int pid = fork();
	if(pid < 0)
		perror("blad");
	if(pid == 0)
		do_child();
	else
		do_parent(pid);
	return 0;
}
