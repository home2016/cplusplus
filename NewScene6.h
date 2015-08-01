#ifndef __NEW_SCENE_6_H__
#define __NEW_SCENE_6_H__

#include "cocos2d.h"

#include "ui\UIWidget.h"
#include "ui\CocosGUI.h"
#include <string.h>
#include "extensions\cocos-ext.h"

using namespace std;
using namespace cocos2d;
using namespace ui;




class NewScene6 : public LayerColor
{


public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);

	
    // implement the "static create()" method manually
    CREATE_FUNC(NewScene6);

	
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

	void btntouch(Ref *pSender);


};

#endif // __HELLOWORLD_SCENE_H__
