#include <iostream>
class Game
{
private:
	Game();
	~Game();
	static Game* myInstance;
protected:
public:
	static void Begin();
	static void End();
	static Game* GetInstance();

};