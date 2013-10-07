#pragma once

#include <map>
#include <vector>
#include "../defines.h"

#ifdef _WIN32
#include <glew.h>
#else
#include "GLES/gl.h"
#endif

namespace star
{
	class Texture2D;

	class TextureManager
	{
	public:
		~TextureManager(void) {}

		static TextureManager* GetInstance();

		bool LoadTexture(const tstring& path, const tstring& name);
		bool DeleteTexture(const tstring& name);
		GLuint GetTextureID(const tstring& name);
		void EraseTextures();

	private:
		//Data Members
		static TextureManager* mTextureManager;
		std::map<tstring, Texture2D*> mTextureList;
		std::vector<tstring> mPathList;

		TextureManager(void) {}

		TextureManager(const TextureManager& yRef);
		TextureManager(TextureManager&& yRef);
		TextureManager& operator=(const TextureManager& yRef);
	};
}