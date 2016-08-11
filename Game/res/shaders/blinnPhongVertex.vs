#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec4 color;

out vec4 colour;
out vec2 texCoord0;
out vec3 normalInterp;
out vec3 vertPos;

uniform mat4 transform;

void main()
{
	colour = vec4(color);
	texCoord0 = uv;
	gl_Position = transform * vec4(position, 1.0);
	vertPos = position;
    normalInterp = transpose(inverse(mat3(transform))) * normal;
}


