#version 330 core
layout (location = 0 ) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 vertexColor;
uniform vec3 color;
uniform vec3 pos;

void main()
{
    gl_Position = vec4(aPos.x / pos.x, aPos.y / pos.y, 0.0, 1.0);
    // gl_Position = vec4(1.0, 1.0, 0.0, 1.0);
    vertexColor = vec4(color, 1.0);
}