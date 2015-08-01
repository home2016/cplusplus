#ifndef __NEW_SCENE_4_H__
#define __NEW_SCENE_4_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "ui\UIWidget.h"
#include "extensions\cocos-ext.h"

//#include "Persona.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace ui;


class NewScene4 : public LayerColor, public EditBoxDelegate
{


public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    

	void goBack(Ref *pSender);

	
	void touchBTNevent(Ref* pSender, Widget::TouchEventType type);


    CREATE_FUNC(NewScene4);
	 
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
    virtual void editBoxEditingDidEnd(EditBox* editBox) ;
    
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


	//void traePersona(Persona p);
	

};

#endif // __HELLOWORLD_SCENE_H__
