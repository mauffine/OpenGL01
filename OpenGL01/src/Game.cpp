#include "Game.h"

bool Game::InitApp()
{
	//Set up Camera
	FlyCamera* pCamera = new FlyCamera();

	pCamera->SetInputWindow(m_window);

	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f);
	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	m_camera = pCamera;
	return true;
}
void Game::DeInitApp()
{

}
bool Game::Update(double dt)
{
	return true;
}
void Game::Draw()
{

}