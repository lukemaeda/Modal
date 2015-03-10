//
//  ModalLayer.cpp
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#include "ModalLayer.h"
#include "ModalSecondScene.h"
using namespace cocos2d;

bool ModalLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // モーダルのフレーム
    auto frame = Sprite::create("frame.png");
    frame->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(frame);
    //透明度を変更(0~255)
    frame->setOpacity(220);
    
    // Menu1
    auto button01 = MenuItemImage::create("menu-image1.png",  // 通常状態の画像
                                            "menu-image1-hover.png",  // 押下状態の画像
                                            CC_CALLBACK_1(ModalLayer::pushMenu01, this));
    // Menu2
    auto button02 = MenuItemImage::create("menu-image2.png",  // 通常状態の画像
                                             "menu-image2-hover.png",  // 押下状態の画像
                                             CC_CALLBACK_1(ModalLayer::pushMenu01, this));
    // キャンセル
    auto closeItem00 = MenuItemImage::create("menu-image9.png",  // 通常状態の画像
                                             "menu-image9-hover.png",  // 押下状態の画像
                                             CC_CALLBACK_1(ModalLayer::menuCloseCallback, this));
    
    // ボタンの設置
    button01->setPosition(Point(winSize.width / 2,winSize.height /1.5));
    button02->setPosition(Point(winSize.width / 2,winSize.height /2.0));
    closeItem00->setPosition(Point(winSize.width / 2,winSize.height /3.5));
    
    auto menu = Menu::create(button01, button02, closeItem00, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // モーダル処理
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [](Touch *touch,Event*event)->bool{
        return true;
    };
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

// menuCloseCallback ModalLayerオブジェクトの削除
void ModalLayer::menuCloseCallback(Ref* pSender)
{
    // ModalLayerオブジェクトの削除
    this->removeFromParentAndCleanup(true);
}

// pushStart01ボタン
void ModalLayer::pushMenu01(Ref *pSender)
{
    CCLOG("pushMenuボタン01");
    
    // 遷移先の画面のインスタンス
    Scene *pScene = ModalSecondScene::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    // 遷移実行  遷移時のアニメーション
    // 直前のsceneはもう使わないから捨ててしまう方法。基本はこれになります。
    Director::getInstance()->replaceScene(transition);
}