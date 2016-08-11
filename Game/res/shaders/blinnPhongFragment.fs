#version 330

precision mediump float; 

in vec3 normalInterp;
in vec3 vertPos;

in vec2 texCoord0;
in vec4 colour;

uniform sampler2D sampler;

const vec3 lightPos = vec3(50.0,50.0,0.0);
const vec3 ambientColor = vec3(0.1, 0.1, 0.1);
const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
const vec3 specColor = vec3(1.0, 1.0, 1.0);
const float shininess = 2.0;
const float screenGamma = 2.2; // Assume the monitor is calibrated to the sRGB color space

void main()
{

	vec3 normal = normalize(normalInterp);
	vec3 lightDir = normalize(lightPos - vertPos);
	vec4 textureColor = texture2D(sampler, texCoord0.xy);
	float lambertian = max(dot(lightDir,normal), 0.0);
	float specular = 0.0;

	if(lambertian > 0.0) {

    vec3 viewDir = normalize(-vertPos);

    // this is blinn phong
    vec3 halfDir = normalize(lightDir + viewDir);
    float specAngle = max(dot(halfDir, normal), 0.0);
    specular = pow(specAngle, shininess);
	}

	 vec3 colorLinear = ambientColor +
                     lambertian * diffuseColor +
                     specular * specColor;

  // apply gamma correction (assume ambientColor, diffuseColor and specColor
  // have been linearized, i.e. have no gamma correction in them)

  vec3 colorGammaCorrected = pow(colorLinear, vec3(1.0/screenGamma));

  // use the gamma corrected color in the fragment

  gl_FragColor = textureColor * vec4(colorGammaCorrected, 1.0);
}