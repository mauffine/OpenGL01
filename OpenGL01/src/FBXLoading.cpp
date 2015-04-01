//#include "FBXLoading.h"
//#include "FlyCamera.h"
//
//#include <iostream>
//bool FBXLoading::InitApp()
//{
//	FlyCamera* pCamera = new FlyCamera(200.f);
//
//	pCamera->SetInputWindow(m_window);
//
//	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f,0.10000000025f,6000.f);
//	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
//	
//	m_camera = pCamera;
//
//	m_fbx = new FBXFile();
//
//	m_fbx->load("./res/models/characters/enemynormal/EnemyNormal.fbx");
//
//	CreateFBXBuffers(m_fbx);
//
//	const char* vsSource = *LoadShader("./res/shaders/FBXvShader.txt");
//	const char* fsSource = *LoadShader("./res/shaders/FBXfShader.txt");
//
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
//	glCompileShader(vertexShader);
//
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
//	glCompileShader(fragmentShader);
//
//	m_program = glCreateProgram();
//	glAttachShader(m_program, vertexShader);
//	glAttachShader(m_program, fragmentShader);
//	glLinkProgram(m_program);
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	int shaderStatus = GL_FALSE;
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderStatus);
//
//	if (shaderStatus == GL_FALSE)
//	{
//		int maxLength = 0;
//
//		glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);
//
//		std::vector<char> errorLog(maxLength);
//		glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &errorLog[0]);
//
//		std::cerr << "Vertex Shader Error" << errorLog.data() << std::endl;
//	}
//
//	shaderStatus = GL_FALSE;
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &shaderStatus);
//	
//	if (shaderStatus == GL_FALSE)
//	{
//		int maxLength = 0;
//
//		glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
//
//		std::vector<char> errorLog(maxLength);
//		glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &errorLog[0]);
//
//		std::cerr << "Vertex Shader Error" << errorLog.data() << std::endl;
//	}
//	int shaderLinked = GL_FALSE;
//	glGetProgramiv(m_program, GL_LINK_STATUS, &shaderStatus);
//	
//	if (shaderStatus == GL_FALSE)
//	{
//		int maxLength = 0;
//
//		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxLength);
//
//		std::vector<char> errorLog(maxLength);
//		glGetProgramInfoLog(m_program, maxLength, &maxLength, &errorLog[0]);
//
//		std::cerr << "Program Linker Error" << errorLog.data() << std::endl;
//	}
//	return true;
//}
//void FBXLoading::DeInitApp()
//{
//	CleanUpFBXBuffers(m_fbx);
//
//	glDeleteProgram(m_program);
//}
//bool FBXLoading::Update(double dt)
//{
//	m_camera->Update(dt);
//
//	FBXSkeleton* skeleton = m_fbx->getSkeletonByIndex(0);
//	FBXAnimation* animation = m_fbx->getAnimationByIndex(0);
//
//
//	return true;
//}
//void FBXLoading::Draw()
//{
//	DisplayGrid(20);
//	glUseProgram(m_program);
//
//	int loc = glGetUniformLocation(m_program, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE,
//	&(m_camera->GetProjectionView()[0][0]));
//	// bind our vertex array object and draw the mesh
//	for (unsigned int i = 0; i < m_fbx->getMeshCount(); ++i) {
//		FBXMeshNode* mesh = m_fbx->getMeshByIndex(i);
//
//		unsigned int* glData = (unsigned int*)mesh->m_userData;
//
//		glBindVertexArray(glData[0]);
//
//		glDrawElements(GL_TRIANGLES,
//			(unsigned int)mesh->m_indices.size(), GL_UNSIGNED_INT, 0);
//	}
//}