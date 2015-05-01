#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <gl_core_4_4.h>
struct Vertex
{
	glm::vec4 position;
	glm::vec2 UV;
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

	unsigned int m_vao, m_vbo, m_ibo;

	int m_procGenShader;
};