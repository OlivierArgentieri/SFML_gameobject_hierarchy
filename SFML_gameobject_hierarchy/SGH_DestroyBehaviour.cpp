#include "SGH_DestroyBehaviour.h"
#include "SGH_GameObject.h"

SGH_DestroyBehaviour::~SGH_DestroyBehaviour()
{
}

void SGH_DestroyBehaviour::TriggerBehaviour(sf::RenderWindow& _w)
{
	if (CanBeDestroy())
		Destroy();
}

void SGH_DestroyBehaviour::Destroy()
{
	if (this->gameObject)
	{
		this->gameObject->SetVisibility(false);
	}
}

bool SGH_DestroyBehaviour::CanBeDestroy()
{
	return GetGameObject()->GetFloatRect().intersects(GetDestructor()->GetFloatRect());
}

SGH_GameObject* SGH_DestroyBehaviour::GetDestructor()
{
	if (destructor)
		return destructor;
	throw std::invalid_argument("NULL DestructorGameObject");

}

SGH_GameObject* SGH_DestroyBehaviour::GetGameObject()
{
	if (gameObject)
		return gameObject;
	
		throw std::invalid_argument("NULL GameObject");


}
