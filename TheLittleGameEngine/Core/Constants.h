#ifndef __TLGE__CONSTANTS_H__
#define __TLGE__CONSTANTS_H__

namespace TLGE
{
	enum ShaderUniforms
	{
		ShaderUniforms_ColorR,
		ShaderUniforms_ColorG,
		ShaderUniforms_ColorB,
		ShaderUniforms_ColorA,
		ShaderUniforms_Texture,
		ShaderUniforms_WorldTransform,
		ShaderUniforms_ViewTransform,
		ShaderUniforms_ProjectionTransform,

		NumShderUniforms,
		ShaderUniforms_Invalid,
	};

	extern char* UNIFORM_NAMES[NumShderUniforms];
}

#endif