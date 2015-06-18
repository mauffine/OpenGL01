#include <iostream>

#include <Gizmos.h>

#include <Engine/GLApplication.h>
#include <Engine/FlyCamera.h>
#include <Engine/TerrainGen.h>
#include <Engine/DirectionalLight.h>
class Game : public GLApplication
{
private:
	TerrainGen* m_pEnvironment;
	DirectionalLight* m_pLight;
	FlyCamera* m_pCamera;
protected:
public:
	Game() : GLApplication("Virtual World") {};
	bool InitApp();
	void DeInitApp();
	bool Update(double dt);
	void Draw();

};