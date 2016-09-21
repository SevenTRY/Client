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
}

pid_t Fork(void)
{
    pid_t	pid;
    
    if ( (pid = fork()) == -1)
        err_sys("fork error");
    return(pid);
}