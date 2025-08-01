#include "nyla.hpp"

#include <csignal>
#include <fcntl.h>
#include <unistd.h>

namespace nyla {

void
quit(State& state)
{
  state.flags.reset(State::Flag_Running);
}

void
spawn(State& state, const char* const command[])
{
  switch (fork()) {
#if 0
    case -1: {
      std::println("fork() failed");
    }
#endif

    case 0: {
      close(xcb_get_file_descriptor(state.xcb.conn));

      {
        int devNull = open("/dev/null", O_RDONLY);
        dup2(devNull, STDIN_FILENO);
        close(devNull);
      }

      {
        int devNull = open("/dev/null", O_WRONLY);
        dup2(devNull, STDOUT_FILENO);
        dup2(devNull, STDERR_FILENO);
        close(devNull);
      }

      setsid();

      struct sigaction sa;
      sigemptyset(&sa.sa_mask);
      sa.sa_flags = 0;
      sa.sa_handler = SIG_DFL;
      sigaction(SIGCHLD, &sa, nullptr);

      execvp(command[0], const_cast<char**>(command));
      std::println(std::cerr, "execvp failed");
      std::exit(EXIT_FAILURE);
    }
  }
}

}
