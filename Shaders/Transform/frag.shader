#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform float rAlpha;

void main()
{

    vec4 texCol = texture(ourTexture, TexCoord);
    texCol.w = rAlpha;
    FragColor = texCol;
}