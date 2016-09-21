//
//  SocketManager.hpp
//  SevenClient
//
//  Created by  TianRunyan on 16/9/11.
//
//

#ifndef SocketManager_h
#define SocketManager_h

#include <stdio.h>


class SocketManager {
    
public:
    
    SocketManager();
    ~SocketManager();
    
    static SocketManager* shareInstance();
    
    bool init();
    
    void testNet();
    
private:
    
    static SocketManager* m_Instance;
    
};

#endif /* SocketManager_h */
