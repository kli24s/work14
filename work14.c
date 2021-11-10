#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

// =============================================================================

static void sighandler(int signo) {

  if (signo == SIGINT) {

    int open_call = open("exitlog", O_CREAT | O_WRONLY | O_APPEND, 0644);

    char *message = "PROGRAM EXITED DUE TO SIGINT\n";
    write(open_call, message, strlen(message));

    close(open_call);

    exit(0);

  }

  if (signo == SIGUSR1) {
    printf("Who you talkin to?\tPPID: %d\n", getppid());
  }

}

// =============================================================================

int main() {

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while (1) {
    sleep(1);
    printf("PID: %d\n", getpid());
  }

  return 0;

}
