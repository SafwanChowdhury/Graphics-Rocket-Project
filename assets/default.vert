#version 430
layout( location = 0 ) in vec3 iPosition;
layout( location = 1 ) in vec3 iAmbient;
layout( location = 2 ) in vec3 iNormal;
layout( location = 3 ) in vec2 iTexCoord;
layout( location = 4 ) in vec3 iDiffuse;
layout( location = 5 ) in vec3 iSpecular;
layout( location = 6 ) in float iShininess;
layout( location = 7 ) in float iAlpha;


layout( location = 0 ) uniform mat4 uProjection;
layout( location = 1 ) uniform mat3 uNormalMatrix;
layout( location = 4 ) uniform mat4 uCamPos;
layout( location = 5 ) uniform mat4 uModel;
layout( location = 6 ) uniform mat4 uView;
layout( location = 7 ) uniform float isTex;
layout( location = 8 ) uniform float isEmi;
layout( location = 9 ) uniform float isMulti;

out vec3 v2fNormal;
out vec3 v2fPos;
out vec3 v2fView;

out vec3 uAmbient;
out vec3 uDiffuse;
out vec3 uSpecular;
out float uShininess;
out float uAlpha;
out vec2 v2fTexCoord;
out float oTex;
out float oEmi;
out float oMulti;


void main()
{
	//send values to fragment shader
	uAmbient = iAmbient;
	uDiffuse = iDiffuse;
	uSpecular = iSpecular;
	uShininess = iShininess;
	uAlpha = iAlpha;
	v2fTexCoord = iTexCoord;
	oTex = isTex;
	oEmi = isEmi;
	oMulti = isMulti;
	v2fNormal = normalize(uNormalMatrix * iNormal);
	v2fPos = vec3(uModel * vec4(iPosition,1.0));
	v2fView = vec3(uCamPos);
	gl_Position = (uProjection * uView  * uModel * vec4( iPosition, 1.0 )); //calculate projcamworld.
}
