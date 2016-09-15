//
//  AvatarConfig.h
//  game1
//
//  Created by NGOCDIEP on 11/3/15.
//
//

#ifndef AvatarConfig_h
#define AvatarConfig_h

//Nếu hướng di chuyển trái - phải và trên dưới dùng chung ảnh. Chỉ quay ngược lại ảnh.
//Hai hướng cơ bản là Right và Top.
#define DIR_BASE 1

enum{
    dirRight = 1,
    dirLeft,
    dirTop,
    dirBot,
};

enum{
    stateIdle = 1,
    stateRun,
    stateJump,
    stateDie,
};


#endif /* AvatarConfig_h */
