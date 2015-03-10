//
//  ModalTopScene.h
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#ifndef __Modal__ModalTopScene__
#define __Modal__ModalTopScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class ModalTopScene : public Layer
{
    
public:
    
    // 初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(ModalTopScene);
};

#endif /* defined(__Modal__ModalTopScene__) */
