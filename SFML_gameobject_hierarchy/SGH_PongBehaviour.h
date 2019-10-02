#pragma onces
#include "SGH_Slider.h"
#include "SGH_BouncyBehaviour.h"
#include "SGH_PongBall.h"

class SGH_PongBehaviour: public SGH_BouncyBehaviour
{
private:
	SGH_Slider* slider;
	SGH_PongBall* pongBall;

	bool IsHitSlider();
	void Bounce(sf::RenderWindow& _w) override;
	
public:
	SGH_PongBehaviour(SGH_Slider* _slider, SGH_PongBall* _pongBall, float _speed) : SGH_BouncyBehaviour(_pongBall, _speed)
	{
		slider = _slider;
		pongBall = _pongBall;
	}
	
	void TriggerBehaviour(sf::RenderWindow& _w) override;
};

