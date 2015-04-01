#ifndef _PARTICLE_SYSTEMS_H_
#define _PARTICLE_SYSTEMS_H_
#include "GLApplication.h"
#include "GPUParticleEmitter.h"
#include "GrassBuilder.h"
class ParticleSystems : public GLApplication
{
private:
	GPUParticleEmitter* m_cloud;
	GPUParticleEmitter* m_rain;
	GPUParticleEmitter* m_upParticles;

	GrassBuilder* m_grass;
public:
	ParticleSystems() : GLApplication("ParticleSystems") {}
	~ParticleSystems() {}

	unsigned int m_vao, m_vbo, m_ibo;

	virtual bool InitApp();
	virtual void DeInitApp();

	virtual bool Update(double a_dt);
	virtual void Draw();


};

#endif