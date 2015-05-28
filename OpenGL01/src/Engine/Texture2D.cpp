#include "Texture2D.h"

Texture2D::Texture2D()
{}
Texture2D::~Texture2D()
{}
void Texture2D::LoadTexture(std::string a_file)
{
	unsigned char* data = stbi_load(a_file.c_str());
}