#pragma once

#include <fstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <Engine/gl_core_4_4.h>

#include <stb_image.h>

#include "Engine/FlyCamera.h"
#include "Engine/DirectionalLight.h"
#include "Engine/GLApplication.h"
#include "Engine/DirectionalLight.h"
struct Vertex
{
	glm::vec4 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
};
class TerrainGen

{
public:
	TerrainGen();
	~TerrainGen();
	bool InitApp(const unsigned int& a_size, const DirectionalLight& a_dirLight);
	void DeInitApp();

	bool Update(double dt);
	void Draw(const FlyCamera& a_camera, const DirectionalLight& a_dirLight);

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

	DirectionalLight m_dirLight;
};