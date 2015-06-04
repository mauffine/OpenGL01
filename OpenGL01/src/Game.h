#include <iostream>

#include <Engine/GLApplication.h>
#include <Engine/FlyCamera.h>
class Game : public GLApplication
{
private:
protected:
public:
	Game() : GLApplication("Virtual World") {};
	bool InitApp();
	void DeInitApp();
	bool Update(double dt);
	void Draw();

};