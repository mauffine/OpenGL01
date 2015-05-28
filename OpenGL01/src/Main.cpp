#include <iostream>
#include "gl_core_4_4.h"
#include <GLFW/glfw3.h>

#include "Tutorials/TerrainGen.h"
int main()
{
	TerrainGen app(100);

	app.Run();
	return 0;
}