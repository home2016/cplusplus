#ifndef __NEW_SCENE_3_H__
#define __NEW_SCENE_3_H__

#include "cocos2d.h"

#include "ui\UIWidget.h"
#include "ui\CocosGUI.h"
#include <string.h>
#include "extensions\cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace ui;
using namespace std;


class NewScene3 : public LayerColor, public EditBoxDelegate
{


public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    

	NewScene3()
	{
		visibleSize = Director::getInstance()->getVisibleSize();
		origin = Director::getInstance()->getVisibleOrigin();
	}

	~NewScene3()
	{}


	Size getVisibleSiz(){return visibleSize; }
	Vec2 getOrigi(){return origin;}


	Button* b1;




	void TouchBevent(Ref* pSender, Widget::TouchEventType type);

	void TouchCBXevent(Ref* pSender, CheckBox::EventType type);


	void volver(Ref* pSender); 


    CREATE_FUNC(NewScene3);
	 

	 /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
	
    virtual void editBoxEditingDidBegin(EditBox* editBox);
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
    virtual void editBoxEditingDidEnd(EditBox* editBox);
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     * @js NA
     * @lua NA
     */
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     * @js NA
     * @lua NA
     */
    virtual void editBoxReturn(EditBox* editBox);
	
	
	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);


	/*
	bool onTouchBegan(Touch *touches, Event *event);
	void onTouchEnded(Touch *touches, Event *event);
	void onTouchMoved(Touch *touches, Event *event);
	*/

private: 

    Size visibleSize; // = Director::getInstance()->getVisibleSize();
    Vec2 origin ;//= Director::getInstance()->getVisibleOrigin();


};

#endif // __HELLOWORLD_SCENE_H__
