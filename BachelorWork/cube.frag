////////////////////////////////////////////////////////////
// Cube Pixel Shader
////////////////////////////////////////////////////////////

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 mvpOut;
in vec4 pos;
in vec3 normal;
in vec3 Position_worldspace;

uniform float section;
uniform sampler2D mainSampler;
uniform int LayerColor;
uniform vec4 LayerColorRGBA;
uniform vec3 positionLighting;

// Ouput data
out vec4 color;


void main(void){

	// MaterialDiffuseColor
	if (LayerColor == 0){
			color = texture2D(mainSampler, UV);
			color.a = 0.4;
		}
	else color = LayerColorRGBA;


	// Section
	if (section == 1)
		if (mvpOut.x > -0.5 && mvpOut.y > 0.99 || mvpOut.x > 0.99 && mvpOut.y > -0.55) 
			discard; 

	
	// Lamp
	if (!(positionLighting.x == 0 && positionLighting.y == 0 && positionLighting.z == 0)){
		// Red light
		//vec4 LightColor = vec4(1,0,0,1);
		// White light
		vec4 LightColor = vec4(1, 1, 1,1);
		// Lite yellow light
		//vec4 LightColor = vec4(0.52,1,1,0.7);


		float LightPower = 350.0f;
		float distance = length(positionLighting - Position_worldspace);
		float cosTheta = clamp( dot( normal,  positionLighting ), 0,1 );

		//color = color * LightColor * cosTheta;
		//color = color * LightColor * cosTheta / (distance*distance);
		color = color * LightColor * LightPower * cosTheta / (distance*distance);
		//color = color * LightColor * LightPower * cosTheta / (distance);
	}
}