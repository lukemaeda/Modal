//
//  ModalSecondScene.h
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#ifndef __Modal__ModalSecondScene__
#define __Modal__ModalSecondScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class ModalSecondScene : public Layer
{
    
public:
    
    // 初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(ModalSecondScene);
};


#endif /* defined(__Modal__ModalSecondScene__) */
