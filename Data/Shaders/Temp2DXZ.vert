attribute vec3 a_Position;
attribute vec2 a_UV;

uniform vec3 u_Position;

varying vec2 v_UV;

void main()
{
	vec3 pos = a_Position + u_Position.xzy;
    gl_Position = vec4(0.01f * pos, 1);
	
	v_UV = a_UV;
}
