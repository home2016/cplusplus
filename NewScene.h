#ifndef __NEW_SCENE_H__
#define __NEW_SCENE_H__

#include "cocos2d.h"

#include "ui\UIWidget.h"
#include "ui\CocosGUI.h"
#include <string.h>
#include "extensions\cocos-ext.h"

using namespace std;
using namespace cocos2d;
using namespace ui;




class NewScene : public LayerColor
{

private:

	int i;


public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Ref* pSender);

	void volver(Ref* pSender);



	void cantidad();

    // implement the "static create()" method manually
    CREATE_FUNC(NewScene);

	void touchEvent(Ref *sender, Widget::TouchEventType type);


	void touchEvent2(Ref *pSender, Widget::TouchEventType type);
	
	void selectedEvent(Ref *pSender, CheckBox::EventType type);


	void setScore(int i){this->i = i;}

	int getScore(){return i;}
	

	NewScene()
	{
		i = 0;
	}


	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);





};

#endif // __HELLOWORLD_SCENE_H__
