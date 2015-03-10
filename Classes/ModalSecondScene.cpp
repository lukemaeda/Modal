//
//  ModalSecondScene.cpp
//  Modal
//
//  Created by MAEDAHAJIME on 2015/03/10.
//
//

#include "ModalSecondScene.h"
// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

Scene* ModalSecondScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = ModalSecondScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool ModalSecondScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    return true;
}
