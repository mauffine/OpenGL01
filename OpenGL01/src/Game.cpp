#include "Game.h"

bool Game::InitApp()
{
	//Set up Camera
	FlyCamera* pCamera = new FlyCamera();

	pCamera->SetInputWindow(m_window);

	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f);
	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	m_camera = pCamera;
	m_pLight = new DirectionalLight(glm::vec3(1.0f, 1.0f, 1.0f), 0.1f, glm::vec3(0, -1, 0), 1.0f, 1.0f);
	m_pEnvironment = new TerrainGen(100, m_pLight);
	return true;
}
void Game::DeInitApp()
{

}
bool Game::Update(double dt)
{
	m_camera->Update(dt);
	m_pEnvironment->Update(dt);
	return true;
}
void Game::Draw()
{
	DisplayGrid(100);
	m_pEnvironment->Draw(*m_camera);

}