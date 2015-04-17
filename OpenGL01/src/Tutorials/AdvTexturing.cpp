//#include "AdvTexturing.h"
//#include "Gizmos.h"
//#include "FlyCamera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include <vector>
//#include <iostream>
//#include <tiny_obj_loader.h>
//bool AdvTexturing::InitApp()
//{
//	FlyCamera* pCamera = new FlyCamera();
//
//	pCamera->SetInputWindow(m_window);
//
//	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f);
//	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
//	
//	m_camera = pCamera;
//
//	
//	int imageWidth = 0, imageHeight = 0, imageFormat = 0;
//	unsigned char* data;
//	//loading DiffuseMap
//	data = stbi_load("./res/textures/rock_diffuse.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
//
//	glGenTextures(1, &m_texture);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	stbi_image_free(data);
//	//finish loading Diffuse
//
//	//load Normal Map
//	data = stbi_load("./res/textures/rock_normal.tga", &imageWidth, &imageHeight, &imageFormat, STBI_default);
//
//	glGenTextures(1, &m_normalMap);
//	glBindTexture(GL_TEXTURE_2D, m_normalMap);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	stbi_image_free(data);
//
//	//shader code
//	const char* vsSource = *LoadShader("./res/shaders/AdvTextfShader.txt");
//	
//	const char* fsSource = *LoadShader("./res/shaders/AdvTextvShader.txt");
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
//	//end shader code
//
//	
//	//DrawData
//	Vertex vertexData[] = {
//	{ -5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
//	{ 5, 0, 5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1 },
//	{ 5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
//	{ -5, 0, -5, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
//	};
//
//	unsigned int indexData[] = {
//		0, 1, 2,
//		0, 2, 3,
//	};
//
//	glGenVertexArrays(1, &m_vao);
//	glBindVertexArray(m_vao);
//
//	glGenBuffers(1, &m_vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6 * 4, vertexData, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &m_ibo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexData, GL_STATIC_DRAW);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0)+48);
//
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0)+16);
//
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0)+32);
//
//	glBindVertexArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//	//use the texure program
//	glUseProgram(m_program);
//
//	//bind to camera
//	int loc = glGetUniformLocation(m_program, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE, &(m_camera->GetProjectionView()[0][0]));
//
//	// set texture slot
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, m_normalMap);
//
//	//tell the shader where it is
//	loc = glGetUniformLocation(m_program, "diffuse");
//	glUniform1i(loc, 0);
//
//	loc = glGetUniformLocation(m_program, "normal");
//	glUniform1i(loc, 1);
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
//
//
//	return true;
//}
//
//void AdvTexturing::DeInitApp()
//{
//}
//
//bool AdvTexturing::Update(double a_dt)
//{
//	m_camera->Update(a_dt);
//	return true;
//}
//
//void AdvTexturing::Draw()
//{
//
//	//bind the light
//	glm::vec3 light(sin(glfwGetTime()), 1, cos(glfwGetTime()));
//	int loc = glGetUniformLocation(m_program, "LightDir");
//	glUniform3f(loc, light.x, light.y, light.z);
//
//	loc = glGetUniformLocation(m_program, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE, &(m_camera->GetProjectionView()[0][0]));
//
//	//draw
//	glBindVertexArray(m_vao);
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
//
//}
