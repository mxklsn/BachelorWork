////////////////////////////////////////////////////////////
// Cube Pixel Shader
////////////////////////////////////////////////////////////

// Interpolated values from the vertex shaders
in vec2 UV;
in vec3 mvpOut;
in vec4 pos;
in vec3 normal;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 LightDirection_cameraspace;

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
		//vec4 LightColor = vec4(1, 1, 1,1);
			// Lite yellow light
		vec4 LightColor = vec4(0.52,1,1,0.7);

			// Normal of the computed fragment, in camera space
		vec3 n = normalize( Normal_cameraspace );
			// Direction of the light (from the fragment to the light)
		vec3 l = normalize( LightDirection_cameraspace );

		vec4 MaterialAmbientColor = vec4(0.1,0.1,0.1,1) * vec4(color);

		float LightPower = 500.0f;
		float distance = length(positionLighting - Position_worldspace);
		float cosTheta = clamp( dot( normal,  positionLighting ), 0,1 );

		color =
		 // Ambient : simulates indirect lighting (distance*distance)
		 MaterialAmbientColor +
		 // Diffuse : "color" of the object
		 color * LightColor * LightPower * cosTheta / (distance) ;
	}
}