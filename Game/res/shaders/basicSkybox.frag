#version 330

in vec3 texCoord;
in vec4 colour;

uniform vec3 color;
uniform samplerCube sampler;


void main()
{
	vec4 textureColor = texture(sampler, texCoord);
	gl_FragColor = textureColor;// * vec4(color, 1);
	//gl_FragColor = colour;
}