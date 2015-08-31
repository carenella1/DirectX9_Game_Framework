#include "Engine_Core.h"

namespace Smoke
{
	TextureManager::TextureManager()
	{
		// Make sure map is empty
		if (!_textureList.empty())
			_textureList.clear();
	}


	TextureManager::~TextureManager() {}


	bool TextureManager::Initialize()
	{
		///////////////////////////////
		// Get texture filenames and 
		// transparency keys from
		// a single file, then add
		// them to the _textureList
		///////////////////////////////
		std::ifstream textureFile("textureList.txt");

		// Store entire line to buffer
		std::string fileInput = "";

		// Filename of texture
		std::string fileName = "";

		// Color keys
		std::string alphaR = "";
		std::string alphaG = "";
		std::string alphaB = "";

		// Loop through entire file
		while (getline(textureFile, fileInput))
		{
			std::istringstream buffer(fileInput);
			buffer >> fileName >> alphaR >> alphaG >> alphaB;

			// Add "bin/" extension to filename
			fileName = "bin/" + fileName;

			// If transparency key is NULL, add texture w/ NULL key
			if (alphaR == "NULL" && alphaG == "NULL" && alphaB == "NULL")
			{
				AddTexture(fileName, NULL);
			}
			// Otherwise, get color key conversions and AddTexture w/ that key
			else
			{
				AddTexture(fileName, D3DCOLOR_XRGB(atoi(alphaR.c_str()), atoi(alphaG.c_str()), atoi(alphaB.c_str())));
			}

			// End loop at end of file
			if (textureFile.eof())
				break;
		}

		textureFile.close();
		return true;
	}


	void TextureManager::AddTexture(std::string textureToStore, D3DCOLOR transparencyKey)
	{
		// Create and add a new texture to the map
		Texture *pTexture = new Texture();
		if (!pTexture->Load(textureToStore, transparencyKey))
		{
			debug << "\tTexture failed to load, name: " + textureToStore << std::endl;
			return;
		}
		_textureList[textureToStore] = pTexture;
	}


	Texture* TextureManager::RetrieveTexture(std::string textureToRetrieve)
	{
		// Create a texture pointer
		Texture* texture = NULL;

		// Get the texture from the map
		if (_textureList[textureToRetrieve])
			texture = static_cast<Texture*>(_textureList[textureToRetrieve]);
		else
			debug << "\tFailed to retrieve texture, name: " + textureToRetrieve << std::endl;

		return texture;
	}


	void TextureManager::Shutdown()
	{
		debug << "TextureManager shutting down..." << std::endl;

		std::map<std::string, Texture*>::iterator tlIt;
		Texture* temp = NULL;
		for (tlIt = _textureList.begin(); tlIt != _textureList.end(); ++tlIt)
		{
			// Get a temp pointer to the texture from map
			temp = static_cast<Texture*>(tlIt->second);

			if (temp == NULL)
				debug << "\tFailed to release a texture, name: " + tlIt->first << std::endl;
			else
			{
				// Release wrapped texture and delete pointer
				temp->Release();
				delete temp;
				temp = NULL;
			}
		}

		// Erase elements in map (should be NULL)
		_textureList.erase(_textureList.begin(), _textureList.end());

		debug << "TextureManager shutdown." << std::endl;
	}
}