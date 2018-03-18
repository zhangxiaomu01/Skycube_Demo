#include "CreateSkybox.h"


GLuint createSkyBox()
{
	//according to different texture resolutions, these values may need to change
	//these numbers correspod to the UV boundaries of particular points
	/*
	    ----
	    | T |
	-----------------
	| F | L | B | R |
	-----------------
	    | D |
	    ----
	Look like this. D- Bottom, B- Back
	*/
	GLuint vao, vbo;
	const float cube_verts[] = { -1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f };

	//generate vao id to hold the mapping from attrib variables in shader to memory locations in vbo
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo); // Generate vbo to hold vertex attributes for triangle

						   //binding vao means that bindbuffer, enablevertexattribarray and vertexattribpointer 
						   // state will be remembered by vao
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo); //specify the buffer where vertex attribute data is stored
										//upload from main memory to gpu memory
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verts), &cube_verts[0], GL_STATIC_DRAW);

	//get the current shader program
	GLint shader_program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &shader_program);

	//get a reference to an attrib variable name in a shader
	GLint pos_loc = glGetAttribLocation(shader_program, "pos_attrib");

	glEnableVertexAttribArray(pos_loc); //enable this attribute

										//tell opengl how to get the attribute values out of the vbo (stride and offset)
	glVertexAttribPointer(pos_loc, 3, GL_FLOAT, false, 0, 0);
	glBindVertexArray(0); //unbind the vao

	return vao;
}

void DrawSkybox(GLuint vao)
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}