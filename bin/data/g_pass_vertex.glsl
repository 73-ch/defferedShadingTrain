#version 330 core

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;

in vec3 position;
in vec3 normal;
in vec2 texcoord;

out vec3 v_position;
out vec3 v_normal;
out vec2 v_texcoord;

void main()
{
    v_position = (modelViewMatrix * vec4(position, 1.0)).xyz;
    v_normal = normalize((modelViewMatrix * vec4(normal, 0.0)).xyz);
    
    //    Position = (view * model * vec4(position, 1.0)).xyz;
    //    Normal = normalize((view * model * vec4(normal, 0.0)).xyz);
    v_texcoord = texcoord;
    
    //    gl_Position = projection * view * model * vec4(position, 1.0);
    gl_Position = modelViewProjectionMatrix * vec4(position, 1.0);
}
