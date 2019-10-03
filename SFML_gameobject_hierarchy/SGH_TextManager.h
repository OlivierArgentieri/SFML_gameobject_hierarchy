#pragma once
class SGH_TextManager
{
private:
	SGH_TextManager* instance;

	SGH_TextManager();
public:
	SGH_TextManager* GetInstance();

	
};