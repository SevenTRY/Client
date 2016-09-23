//
//  SocketManager.cpp
//  SevenClient
//
//  Created by  TianRunyan on 16/9/11.
//
//

#include "SocketManager.h"
#include "../lib/common.h"

USING_NS_CC;

SocketManager* SocketManager::m_Instance  = NULL;

SocketManager::SocketManager(){
}

SocketManager::~SocketManager(){
}

SocketManager* SocketManager::shareInstance(){
    if(m_Instance == NULL){
        m_Instance = new SocketManager();
        m_Instance->init();
    }
    
    return m_Instance;
}

bool SocketManager::init(){
    testNet();
    return true;
}

void SocketManager::testNet(){
    
    int sockfd;
    struct sockaddr_in servaddr;
    
    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    
    Inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    
    Connect(sockfd, (SA *)&servaddr, sizeof(servaddr));
    
    FILE* file;
    
    file = fopen(FileUtils::getInstance()->fullPathForFilename("text.txt").c_str(), "r");
    
    str_cli(file, sockfd);
    
}