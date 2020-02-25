precision highp float;

uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;

varying vec4 vPosition;
varying vec3 vNormal;
varying vec2 vUv;

void main() {
    vec3 colour = vec3(1.0);
    vec3 light = vec3(50.0);

    vec3 warm = vec3(0.3, 0.2, 0.1) + colour * 0.45;
    vec3 cool = vec3(0.0, 0.1, 0.3) + colour * 0.45;

    vec3 l = normalize(light - vPosition.xyz);
    vec3 n = normalize(vNormal);
    float diffuse = max(0.0, dot(n, l));

    float shade = dot(vNormal, normalize(light));

    colour = mix(cool, warm, diffuse);
    colour *= smoothstep(-1.0, 1.0, shade);




    gl_FragColor = vec4(colour,1.0);
}
