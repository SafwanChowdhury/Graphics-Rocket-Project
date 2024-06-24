#include "simple_mesh.hpp"
#include <iostream>
#include <filesystem>
using namespace std;

SimpleMeshData concatenate(SimpleMeshData aM, SimpleMeshData const& aN)
{
	aM.positions.insert(aM.positions.end(), aN.positions.begin(), aN.positions.end());
	aM.normals.insert(aM.normals.end(), aN.normals.begin(), aN.normals.end());
	aM.texcoords.insert(aM.texcoords.end(), aN.texcoords.begin(), aN.texcoords.end());
	aM.material.ambient.insert(aM.material.ambient.end(), aN.material.ambient.begin(), aN.material.ambient.end());
	aM.material.diffuse.insert(aM.material.diffuse.end(), aN.material.diffuse.begin(), aN.material.diffuse.end());
	aM.material.specular.insert(aM.material.specular.end(), aN.material.specular.begin(), aN.material.specular.end());
	aM.material.shininess.insert(aM.material.shininess.end(), aN.material.shininess.begin(), aN.material.shininess.end());
	aM.material.alpha.insert(aM.material.alpha.end(), aN.material.alpha.begin(), aN.material.alpha.end());
	return aM;
}


GLuint create_vao(SimpleMeshData const& aMeshData)
{

	GLuint position = 0;
	glGenBuffers(1, &position);
	glBindBuffer(GL_ARRAY_BUFFER, position);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.positions.size() * sizeof(Vec3f), aMeshData.positions.data(), GL_STATIC_DRAW);

	GLuint ambient = 0;
	glGenBuffers(1, &ambient);
	glBindBuffer(GL_ARRAY_BUFFER, ambient);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.material.ambient.size() * sizeof(Vec3f), aMeshData.material.ambient.data(), GL_STATIC_DRAW);

	GLuint normals = 0;
	glGenBuffers(1, &normals);
	glBindBuffer(GL_ARRAY_BUFFER, normals);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.normals.size() * sizeof(Vec3f), aMeshData.normals.data(), GL_STATIC_DRAW);

	GLuint diffuse = 0;
	glGenBuffers(1, &diffuse);
	glBindBuffer(GL_ARRAY_BUFFER, diffuse);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.material.diffuse.size() * sizeof(Vec3f), aMeshData.material.diffuse.data(), GL_STATIC_DRAW);

	GLuint specular = 0;
	glGenBuffers(1, &specular);
	glBindBuffer(GL_ARRAY_BUFFER, specular);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.material.specular.size() * sizeof(Vec3f), aMeshData.material.specular.data(), GL_STATIC_DRAW);

	GLuint shininess = 0;
	glGenBuffers(1, &shininess);
	glBindBuffer(GL_ARRAY_BUFFER, shininess);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.material.shininess.size() * sizeof(float), aMeshData.material.shininess.data(), GL_STATIC_DRAW);

	GLuint alpha = 0;
	glGenBuffers(1, &alpha);
	glBindBuffer(GL_ARRAY_BUFFER, alpha);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.material.alpha.size() * sizeof(float), aMeshData.material.alpha.data(), GL_STATIC_DRAW);

	GLuint texcoords = 0;
	glGenBuffers(1, &texcoords);
	glBindBuffer(GL_ARRAY_BUFFER, texcoords);
	glBufferData(GL_ARRAY_BUFFER, aMeshData.texcoords.size() * sizeof(Vec2f), aMeshData.texcoords.data(), GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, position);

	glVertexAttribPointer(
		0, // location = 0 in vertex shader
		3, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, ambient);

	glVertexAttribPointer(
		1, // location = 1 in vertex shader
		3, GL_FLOAT, GL_FALSE,
		0, // see above
		0
	);

	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, normals);

	glVertexAttribPointer(
		2, // location = 2 in vertex shader
		3, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(2);

	//texture
	glBindBuffer(GL_ARRAY_BUFFER, texcoords);

	glVertexAttribPointer(
		3, // location = 3 in vertex shader
		2, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, diffuse);

	glVertexAttribPointer(
		4, // location = 4 in vertex shader
		3, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(4);

	glBindBuffer(GL_ARRAY_BUFFER, specular);

	glVertexAttribPointer(
		5, // location = 5 in vertex shader
		3, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(5);

	glBindBuffer(GL_ARRAY_BUFFER, shininess);

	glVertexAttribPointer(
		6, // location = 6 in vertex shader
		1, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(6);

	glBindBuffer(GL_ARRAY_BUFFER, alpha);

	glVertexAttribPointer(
		7, // location = 7 in vertex shader
		1, GL_FLOAT, GL_FALSE,
		0, // stride = 0 indicates that there is no padding between inputs
		0 // data starts at offset 0 in the VBO
	);
	glEnableVertexAttribArray(7);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &position);
	glDeleteBuffers(1, &normals);
	glDeleteBuffers(1, &ambient);
	glDeleteBuffers(1, &diffuse);
	glDeleteBuffers(1, &specular);
	glDeleteBuffers(1, &shininess);
	glDeleteBuffers(1, &alpha);
	glDeleteBuffers(1, &texcoords);


	return vao;
}

//method to load textures using stbi_load
GLuint load_texture_2d (char const* aPath) {
  assert(aPath);
    
  GLuint tex = 0;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
    
  stbi_set_flip_vertically_on_load(true);

  int w, h, channels;

  stbi_uc* ptr = stbi_load(aPath, &w, &h, &channels, 4);
    
    if (ptr){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_SRGB8_ALPHA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, ptr);
    }
    else
    {
        std::cout << "2D texture failed to load at path: " << aPath << std::endl;
        stbi_image_free(ptr);
    }


  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  stbi_image_free(ptr);

  glGenerateMipmap(GL_TEXTURE_2D);

  return tex;
}

//method to load cubemap textures using stbi_load
GLuint load_cubemap(std::vector<std::string> faces) {
	GLuint textureID = 0;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	stbi_set_flip_vertically_on_load(0); //dont flip image on load
	int width, height, nrComponents;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}
