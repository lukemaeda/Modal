//
//  ModalTopScene.cpp
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#include "ModalTopScene.h"
#include "ModalLayer.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* ModalTopScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = ModalTopScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    //////////////////////////////////////
    // モーダルレイヤーを追加
    auto modalLayer = ModalLayer::create();
    scene->addChild(modalLayer);
    //////////////////////////////////////
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool ModalTopScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    auto Sprite = Sprite::create("Default-568@2x.png");
    Sprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(Sprite);
    
    return true;
}
