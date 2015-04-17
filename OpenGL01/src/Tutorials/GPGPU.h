#pragma once
#include <GLApplication.h>
class GPGPU : GLApplication
{
public:
	GPGPU() : GLApplication("GPGPU Tutorial") {}
	~GPGPU() {}
	
	unsigned int m_vao, m_vbo, m_ibo;
	
	virtual bool InitApp();
	virtual void DeInitApp();
	
	virtual bool Update(double a_dt);
	virtual void Draw();
private:
};