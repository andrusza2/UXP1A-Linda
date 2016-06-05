#ifndef LINDAINTERFACE_H
#define LINDAINTERFACE_H


class LindaInterface
{
    int r_pipefd;
    int w_pipefd;
public:
    LindaInterface(int r_pipefd, int w_pipefd):
        r_pipefd(r_pipefd), w_pipefd(w_pipefd) { }
};

#endif // LINDAINTERFACE_H
