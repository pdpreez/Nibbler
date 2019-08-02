#version 330 core
layout (location = 0 ) in vec3 aPos;

uniform vec3 color;
uniform vec3 pos;

void main()
{
    gl_Position = vec4((aPos.x + pos.x) / 40, (aPos.y  + pos.y) / 30, 0.0, 1.0);
    gl_Position.xy = gl_Position.xy * 2;
    gl_Position.xy += vec2(-1.0, -1.0);
}