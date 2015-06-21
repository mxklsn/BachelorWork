// Ouput data
out vec4 color;

in vec3 pos;
in vec3 fragmentColor;

void main()
{
	//vec3 center = vec3(centerCubeOut.x, centerCubeOut.y, centerCubeOut.z);

	//float r = abs(distance(pos, center))/(int(centerCubeOut.w) % 1000);
	//float g = abs(distance(pos, center))/(int(centerCubeOut.w / 1000) % 1000);
	//float b = abs(distance(pos, center))/(int(centerCubeOut.w / 1000 / 1000));
	//color = vec4(r, g, b, 1);

	//color = vec4(vec3(distance(pos, center)/centerCubeOut.w, distance(pos, center)/centerCubeOut.w, distance(pos, center))/centerCubeOut.w, 1);
	color = vec4(fragmentColor, 1);
}