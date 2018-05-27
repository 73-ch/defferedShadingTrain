#version 330 core

const int light_num = 50;

uniform vec3 l_positions[light_num];
uniform vec3 l_ambients[light_num];
uniform vec3 l_diffuses[light_num];
uniform vec3 l_speculars[light_num];

uniform sampler2D g_position;
uniform sampler2D g_normal;
uniform sampler2D g_albedo;
uniform sampler2D g_depth;

uniform vec3 cam_pos;

in vec2 v_texcoord;

out vec4 out_color;

void main() {
    vec3 position = texture(g_position, v_texcoord).xyz;
    vec3 normal = texture(g_normal, v_texcoord).xyz;
    vec3 albedo = texture(g_albedo, v_texcoord).xyz;
    
    vec3 lighting = vec3(0.);
    
    for (int i = 0; i < light_num; i++) {
        float dist = length(l_positions[i] - position);
        
        if (dist < 1000) {
            vec3 light_dir = normalize(l_positions[i] - position);
            vec3 diffuse = max(dot(normal, light_dir), 0.0) * l_diffuses[i];
            
            vec3 cam_dir = normalize(cam_pos - position);
            vec3 halfway_dir = normalize(cam_dir + light_dir);
            float spec = pow(max(dot(normal, halfway_dir), 0.0), 16.0);
            vec3 specular = l_speculars[i] * spec;
            
            float attenuation = 1.0 + (0.1 * dist) + (0.01* dist * dist);
            
            lighting += (l_ambients[i] + diffuse + specular)/attenuation;
        }
    }
    
    out_color = vec4(position, 1.0);
}

