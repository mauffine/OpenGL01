//#include "Tut3.h"
//#include "Gizmos.h"
//#include "FlyCamera.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include <stb_image.h>
//#include <vector>
//#include <iostream>
//#include <tiny_obj_loader.h>
//
//bool Tut3::InitApp()
//{
//	FlyCamera* pCamera = new FlyCamera();
//
//	pCamera->SetInputWindow(m_window);
//
//	pCamera->SetupPerspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f);
//	pCamera->LookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
//	
//	m_camera = pCamera;
//	this->CreateGLLightShaders();
//	this->LoadObj("bunny");
//	this->CreateOpenGLBuffers(shapes);
//	return true;
//}
//void Tut3::DeInitApp()
//{
//
//}
//bool Tut3::Update(double a_dt)
//{
//	m_camera->Update(a_dt);
//	return true;
//}
//
//void Tut3::Draw()
//{
//	DisplayGrid(20);
//
//	glUseProgram(m_program);
//
//	int loc = glGetUniformLocation(m_program, "ProjectionView");
//	glUniformMatrix4fv(loc, 1, GL_FALSE, (float*) &m_camera->GetProjectionView());
//
//	loc = glGetUniformLocation(m_program, "LightDirection");
//	glUniform3f(loc, 0, 1, 0);
//
//	loc = glGetUniformLocation(m_program, "LightColor");
//	glUniform3f(loc, 1, 1, 1);
//
//	loc = glGetUniformLocation(m_program, "SpecPow");
//	glUniform1f(loc, 128);
//
//	loc = glGetUniformLocation(m_program, "CameraPos");
//	glUniform3f(loc, m_camera->GetPosition().x, m_camera->GetPosition().y, m_camera->GetPosition().z);
//	
//	//draw
//	for (unsigned int i = 0; i < m_gl_info.size(); ++i)
//	{
//		glBindVertexArray(m_gl_info[i].m_VAO);
//		glDrawElements(GL_TRIANGLES, m_gl_info[i].m_index_count, GL_UNSIGNED_INT, 0);
//	}
//
//}