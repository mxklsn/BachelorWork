

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 mvp;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 normalPoints;

// Output data ; will be interpolated for each fragment.
out vec2 UV;
out vec4 pos;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  MVP * vec4(mvp, 1);
	pos = gl_Position;
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}

