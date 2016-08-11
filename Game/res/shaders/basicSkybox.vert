#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec4 color;

out vec4 colour;
out vec3 texCoord;

uniform mat4 transform;

void main()
{
	colour = vec4(color);
	texCoord = position;
	vec4 pos = transform * vec4(position, 1.0);
	gl_Position = pos;
}