#include <iostream>
#include <vector>
#include "lindainterface.h"

using namespace std;

const size_t CLIENT_COUNT = 4;

int in_pipes[CLIENT_COUNT];
int out_pipes[CLIENT_COUNT];

extern int client_main(LindaInterface);

int main(int argc, char *argv[])
{
    for(size_t i=0; i<CLIENT_COUNT; i++)
    {
        int in_pipefd[2];
        int out_pipefd[2];

        if(pipe(in_pipefd) == -1)
            break; // error
        if(pipe(out_pipefd) == -1)
            break; // error

        in_pipes[i]  = in_pipefd[0];
        out_pipes[i] = out_pipefd[1];

        pid_t c_pid = fork();

        if(c_pid < 0)
            break; // error

        if(c_pid == 0)
        {
            // Client init
            close(in_pipefd[0]);
            close(out_pipefd[1]);
            return client_main(LindaInterface(out_pipefd[0], in_pipefd[1]));
        }

        // Here is server code

        close(in_pipefd[1]);
        close(out_pipefd[0]);
    }

    // Server code
    fd_set req_descriptors;

    FD_ZERO(&req_descriptors);
    for(size_t i=0; i<CLIENT_COUNT; i++)
        FD_SET(in_pipes[i], &req_descriptors);

    while(1)
    {
        if(select(CLIENT_COUNT, &req_descriptors, nullptr, nullptr, nullptr) == -1)
            break; // error

        for(size_t i=0; i<CLIENT_COUNT; i++)
            if(FD_ISSET(in_pipes[i], &req_descriptors))
            {
                // receiving request
            }
    }

    return 0;
}
