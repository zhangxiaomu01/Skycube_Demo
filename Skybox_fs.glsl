#version 430

layout (location = 2) uniform sampler2D diffuse_color;
layout (location = 0) uniform samplerCube cubemap;
out vec4 fragcolor;

       
//in vec2 tex_coord;
in vec3 pos;   
      
void main(void)
{   
	fragcolor = texture(cubemap, pos);
}




















