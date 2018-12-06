attribute vec3 a_Position;
attribute vec2 a_UV;

uniform mat4 u_WorldTransform;
uniform mat4 u_ViewTransform;
uniform mat4 u_ProjectionTransform;

varying vec2 v_UV;

void main()
{
	vec4 objectPosition = vec4(a_Position, 1);
	vec4 worldPosition = u_WorldTransform * objectPosition;
	vec4 viewPosition = u_ViewTransform * worldPosition;
	vec4 clipPosition = u_ProjectionTransform * viewPosition;
	
	gl_Position = clipPosition;

	v_UV = a_UV;
}