#pragma once

#include <fstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <gl_core_4_4.h>

#include <stb_image.h>

#include "Engine/GLApplication.h"
#include "Engine/FlyCamera.h"
struct Vertex
{
	glm::vec4 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
};
class TerrainGen : public GLApplication

{
public:
	bool InitApp(unsigned int a_size);
	void DeInitApp();

	bool Update(double dt);
	void Draw();

	void GenerateEnvironment();
private:
	Vertex* m_vertexData;
	unsigned int* m_indicies;
	
	int m_terrainShader;

	unsigned int m_size;
	unsigned int m_vao, m_vbo, m_ibo;

	float m_seed;
	int m_terrainGenProgram;
	

	void GeneratePlane();
	void GenerateBuffers();

	unsigned int m_diffuseID;
	int m_diffuseHeight, m_diffuseWidth, m_imageType;


	const char** LoadShader(const char* a_FileName);
};