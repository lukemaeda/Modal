//
//  ModalLayer.h
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#ifndef __Modal__ModalLayer__
#define __Modal__ModalLayer__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class ModalLayer : public cocos2d::Layer
{
    
public:

    virtual bool init();
    
    void menuCloseCallback(Ref* pSender);
    
    void pushMenu01(Ref *pSender);
    
    // create()を使えるようにしている。
    CREATE_FUNC(ModalLayer);
};

#endif /* defined(__Modal__ModalLayer__) */
