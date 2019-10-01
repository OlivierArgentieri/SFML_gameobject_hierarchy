#pragma once
class SGH_GameObject;

class SGH_Behaviour
{
private:
	SGH_GameObject* gameObject;
public:
	virtual void TriggerBehaviour() =0;
};
