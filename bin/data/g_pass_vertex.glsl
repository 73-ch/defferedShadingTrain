#version 330 core

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec3 position;
in vec3 normal;
in vec2 texcoord;

out vec3 Position;
out vec3 Normal;
out vec2 TexCoord;

void main()
{
    Position = (modelViewMatrix * vec4(position, 1.0)).xyz;
    Normal = normalize((modelViewMatrix * vec4(normal, 0.0)).xyz);
    
    //    Position = (view * model * vec4(position, 1.0)).xyz;
    //    Normal = normalize((view * model * vec4(normal, 0.0)).xyz);
    TexCoord = texcoord;
    
    //    gl_Position = projection * view * model * vec4(position, 1.0);
    gl_Position = modelViewProjectionMatrix * vec4(position, 1.0);
}
