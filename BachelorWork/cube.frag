////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 mvpOut;
in vec4 pos;
in vec3 normal;

uniform float section;
uniform sampler2D mainSampler;
uniform int LayerColor;
uniform vec4 LayerColorRGBA;
uniform vec3 positionLighting;


// Ouput data
out vec4 color;

void main(void){

	// Output color = color of the texture at the specified UV
	//color.g *= 2;
	//color = normalize(vec3(pos.x, pos.y, pos.z));
	//color.r = 1;
	if (LayerColor == 0){
			color = texture2D(mainSampler, UV);
			color.a = 0.4;
		}
	else {
		color = LayerColorRGBA;
	}
	if (section == 1)
		if (mvpOut.x > -0.5 && mvpOut.y > 0.99 || mvpOut.x > 0.99 && mvpOut.y > -0.55) 
			discard; 

	
	//The lamp
	if (!(positionLighting.x == 0 && positionLighting.y == 0 && positionLighting.z == 0))
	{

		//float cosTheta = dot( normal, vec3(-1,-1,-1)  );
		float cosTheta = clamp( dot( normal,  positionLighting ), 0,1 );
		color = color * vec4(1,0,0,1) * cosTheta;
		//color = color * vec4(0.52,1,1,0.7) * cosTheta;
	}
}