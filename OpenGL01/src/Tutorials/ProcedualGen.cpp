#include "ProcedualGen.h"

ProcedualGen::ProcedualGen()
{
	for (int i = 0; i < 20; ++i)
	{
		for (int x = 0; x < 20; ++x)
		{
			vertexData[i][x]->position = glm::vec4(i, 0, x, 1);
		}
	}
	m_procGenShader = glCreateProgram();

}
ProcedualGen::~ProcedualGen()
{
}
void ProcedualGen::GenerateEnvironment()
{
}
void ProcedualGen::Draw(const glm::mat4& a_projectionView)
{
	
}