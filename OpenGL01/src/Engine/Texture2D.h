#include <string>
#include <stb_image.h>
class Texture2D
{
public:
	Texture2D();
	~Texture2D();
private:
	unsigned int m_ID;
	void LoadTexture(std::string a_file);

	unsigned int m_imageHeight, m_imageWidth, m_imageType;
};