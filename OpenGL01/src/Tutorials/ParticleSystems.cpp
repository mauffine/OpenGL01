#include "Tutorials/ParticleSystems.h"
#include "FlyCamera.h"

bool ParticleSystems::InitApp()
{
	m_grass = new GrassBuilder(glm::vec3(0, .5f, 0), 1);
	m_cloud = new GPUParticleEmitter();
	m_cloud->Initialise(50000,
		.1f, 5.f,
		5, 20,
		1, 0.1f,
		glm::vec4(.2f, .2f, .2f, 1), glm::vec4(.8f, .8f, .8f, .2f), "./res/shaders/GPUParticleCloud.vert");
	m_rain = new GPUParticleEmitter();
	m_rain->Initialise(500000,
		.5f, 1.f,
		5, 20,
		.1f, 0.1f,
		glm::vec4(.2, .2, 1, 1), glm::vec4(.2, .2, 1, 1), "./res/shaders/GPUParticle.vert");
	m_upParticles = new GPUParticleEmitter();
	m_upParticles->Initialise(30,
		13.f, 15.f,
		5, 20,
		.5f, 0.1f,
		glm::vec4(1, 1, 1, 1), glm::vec4(1, 1, 1, 0), "./res/shaders/GPUParticleUp.vert");
	m_upParticles->m_position = glm::vec3(-50, 0, -50);
	FlyCamera* pCamera = new FlyCamera();

	pCamera->SetInputWindow(m_window);

	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f);
	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	m_camera = pCamera;

	const char* vsSource = *LoadShader("./res/shaders/ParticlevShader.txt");
	const char* fsSource = *LoadShader("./res/shaders/ParticlefShader.txt");

	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vs, 1, &vsSource, nullptr);
	glShaderSource(fs, 1, &fsSource, nullptr);
	glCompileShader(fs);
	glCompileShader(vs);
	m_program = glCreateProgram();
	glAttachShader(m_program, vs);
	glAttachShader(m_program, fs);
	glLinkProgram(m_program);
	glDeleteShader(fs);
	glDeleteShader(vs);

	//static const int Vector_Count = 5000000;
	//glm::vec4 m_vectors[Vector_Count];

	//for (auto& v : m_vectors)
	//	v = glm::vec4(1);

	//double startTime = glfwGetTime();

	//for (auto& v : m_vectors)
	//	v = glm::normalize(v);

	//double endTime = glfwGetTime();
	//printf("CPU duration %f\n", endTime - startTime);

	//// get the first platform
	//cl_int result = clGetPlatformIDs(1, &m_platform, nullptr);
	//if (result != CL_SUCCESS)
	//	printf("clGetPlatformIDs failed %i\n", result);

	////get the first device on the plaform (default is GPU)
	//result = clGetDeviceIDs(m_platform, CL_DEVICE_TYPE_DEFAULT, 1, &m_device, nullptr);

	//if (result != CL_SUCCESS)
	//	printf("clGetDeviceIDs failed %i\n", result);

	return true;
}
void ParticleSystems::DeInitApp()
{
}
bool ParticleSystems::Update(double a_dt)
{
	m_camera->Update(a_dt);
	return true;
}
void ParticleSystems::Draw()
{
	glUseProgram(m_program);

	int loc = glGetUniformLocation(m_program, "projectionView");
	glUniformMatrix4fv(loc, 1, GL_FALSE,
		&m_camera->GetProjectionView()[0][0]);
	
	m_rain->Draw((float)glfwGetTime(),
		m_camera->GetTransform(),
		m_camera->GetProjectionView());

	m_cloud->Draw((float)glfwGetTime(),
		m_camera->GetTransform(),
		m_camera->GetProjectionView());

	m_upParticles->Draw((float)glfwGetTime(),
		m_camera->GetTransform(),
		m_camera->GetProjectionView());

	m_grass->Draw( m_camera->GetProjectionView());
	DisplayGrid(100);
}