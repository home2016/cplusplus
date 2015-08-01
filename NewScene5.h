#ifndef __NEW_SCENE_5_H__
#define __NEW_SCENE_5_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "ui\UIWidget.h"
#include "extensions\cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

//using namespace cocos2d::network;
using namespace ui;
using namespace std;


class NewScene5 : public Layer, public ScrollViewDelegate
{
	
private:

	//cocos2d::network::WebSocket * _webSocket;

	

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    


    // implement the "static create()" method manually
    CREATE_FUNC(NewScene5);


	/*
	//abrir la conexion
	virtual void onOpen(cocos2d::network::WebSocket* ws);
	//cuando se recibe la conexion o un mensaje del servidor
	virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
	// cuando se cierra la conexion
	virtual void onClose(cocos2d::network::WebSocket* ws);
	// cuando da error la conexion
	virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
	*/

	void btntouch(Ref *pSender);




	void menuItemCallback(Ref* sender);


	void onKeyReleased(EventKeyboard::KeyCode keycode, Event *event);

	 /**
     * @js NA
     * @lua NA
     */
    virtual void scrollViewDidScroll(extension::ScrollView* view);
    /**
     * @js NA
     * @lua NA
     */
    virtual void scrollViewDidZoom(extension::ScrollView* view);
	
};

#endif // __HELLOWORLD_SCENE_H__
