#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;
layout (location = 3) in vec4 color;

out vec4 colour;
out vec2 texCoord;

uniform mat4 transform;
uniform int time;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
	float intensity = 0.02;
	colour = vec4(color);
	texCoord = uv;
	vec4 pos = transform * vec4(position + normal * sin(time * rand(position.xy) / 100) * intensity, 1.0);
	gl_Position = pos;
}