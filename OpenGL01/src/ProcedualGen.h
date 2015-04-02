#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <gl_core_4_4.h>
struct Vertex
{
	glm::vec4 position;
};
class ProcedualGen
{
public:
	ProcedualGen();
	~ProcedualGen();
	void GenerateEnvironment();
	void Draw(const glm::mat4& a_projectionView);
private:
	Vertex* vertexData[20][20];

	int m_procGenShader;
};