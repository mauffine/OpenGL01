//#include "Tut2.h"
//#include "Gizmos.h"
//#include "FlyCamera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include <vector>
//#include <iostream>
//#include <tiny_obj_loader.h>
//bool Tut2::InitApp()
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
//	//loading 2d texture
//	int imageWidth = 0, imageHeight = 0, imageFormat = 0;
//
//	unsigned char* data = stbi_load("./res/textures/crate.png", &imageWidth, &imageHeight, &imageFormat, STBI_default);
//
//	unsigned int m_texture;
//
//	glGenTextures(1, &m_texture);
//	glBindTexture(GL_TEXTURE_2D, m_texture);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//	stbi_image_free(data);
//	//finish loading 2d texture
//
//	//shader code
//	const char* vsSource = "#version 410\n \
//						   layout(location=0) in vec4 Position; \
//						   layout(location=1) in vec2 TexCoord; \
//						   out vec2 vTexCoord; \
//						   uniform mat4 ProjectionView; \
//						   void main() { \
//						   vTexCoord = TexCoord; \
//						   gl_Position= ProjectionView * Position; \
//						   }";
//	const char* fsSource = "#version 410\n \
//						   in vec2 vTexCoord; \
//						   out vec4 FragColor; \
//						   uniform sampler2D diffuse; \
//						   void main() { \
//						   FragColor = texture(diffuse, vTexCoord);\
//						   }";
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
//	float vertexData[] = {
//		-5, 0, 5, 1, 0, 1, 
//		5, 0, 5, 1, 1, 1, 
//		5, 0, -5, 1, 1, 0, 
//		-5, 0, -5, 1, 0, 0,
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
//	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, vertexData, GL_STATIC_DRAW);
//
//	glGenBuffers(1, &m_ibo);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, indexData, GL_STATIC_DRAW);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
//
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, ((char*)0)+16);
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
//	//tell the shader where it is
//	loc = glGetUniformLocation(m_program, "diffuse");
//	glUniform1i(loc, 0);
//
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
//void Tut2::DeInitApp()
//{
//}
//
//bool Tut2::Update(double a_dt)
//{
//	m_camera->Update(a_dt);
//	return true;
//}
//
//void Tut2::Draw()
//{
//	int loc = glGetUniformLocation(m_program, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE, &(m_camera->GetProjectionView()[0][0]));
//
//	//draw
//	glBindVertexArray(m_vao);
//	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
//
//}
