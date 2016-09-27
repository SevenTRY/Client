//
//  commsock.cpp
//  SevenClient
//
//  Created by  TianRunyan on 16/9/11.
//
//

#include <stdio.h>
#include "common.h"

int Socket(int family,int type,int protocol){
    
    int n;
    if((n = socket(family, type, protocol))<0)
        err_sys("socket error");
    return n;    
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if (connect(fd, sa, salen) < 0)
        err_sys("connect error");
    CCLOG("connect succeed!");
}

pid_t Fork(void)
{
    pid_t	pid;
    
    if ( (pid = fork()) == -1)
        err_sys("fork error");
    return(pid);
}

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds,
           struct timeval *timeout)
{
    int		n;
    
    if ( (n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
        err_sys("select error");
    return(n);		/* can return 0 on timeout */
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
    ssize_t		n;
    
    if ( (n = read(fd, ptr, nbytes)) == -1)
        err_sys("read error");
    return(n);
}

void Write(int fd, void *ptr, size_t nbytes)
{
    if (write(fd, ptr, nbytes) != nbytes)
        err_sys("write error");
}

void Shutdown(int fd, int how)
{
    if (shutdown(fd, how) < 0)
        err_sys("shutdown error");
}