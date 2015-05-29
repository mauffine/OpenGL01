#include <iostream>

#include <Engine/GLApplication.h>
class Game : public GLApplication
{
private:
protected:
public:
	bool InitApp();
	void DeInitApp();
	bool Update(double dt);
	void Draw();

};