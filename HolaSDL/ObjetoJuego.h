#pragma once
class ObjetoJuego
{
public:

	ObjetoJuego()
	{
	}

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual bool onClick() = 0;



	virtual ~ObjetoJuego()
	{
	}
};

