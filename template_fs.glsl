#version 430

layout(location = 0) uniform sampler2D diffuse_color;

out vec4 fragcolor;           
in vec2 tex_coord;
      
void main(void)
{   
	fragcolor = texture(diffuse_color, tex_coord);
	//fragcolor = vec4(tex_coord.xy, 0.0f, 1.0f);
}




















