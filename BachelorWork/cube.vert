////////////////////////////////////////////////////////////
// Vertex Shader
////////////////////////////////////////////////////////////



// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 mvp;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 normalPoints;

// Output data ; will be interpolated for each fragment.
out vec2 UV;
out vec4 pos;
out vec3 mvpOut;
out vec3 normal;


// Values that stay constant for the whole mesh.
uniform mat4 MVP;
uniform vec3 position;
uniform vec3 size;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;


void main(void){

	// Output position of the vertex, in clip space : MVP * position
	vec3 new_position = mvp;
	mat4 size_matrix = mat4(1);
	size_matrix[0][0] = size.x;
	size_matrix[1][1] = size.y;
	size_matrix[2][2] = size.z;
	mat4 pos_matrix = mat4(1);
	pos_matrix[0][3] = position.x;
	pos_matrix[1][3] = position.y;
	pos_matrix[2][3] = position.z;
	mat4 res = size_matrix*pos_matrix;
	gl_Position =  MVP * (vec4(new_position, 1)*res);
	// gl_Position =  MVP * (vec4(mvp, 1)*res);
	pos = gl_Position;

	// UV of the vertex. No special space for this one.
	UV = vertexUV;
	mvpOut = mvp;

	//The lamp
	normal = normalize(normalPoints);

	// Normal of the computed fragment, in camera space
	//vec3 normal = normalize( Normal_cameraspace );
	// Direction of the light (from the fragment to the light)
	//vec3 l = normalize( LightDirection_cameraspace );



}




