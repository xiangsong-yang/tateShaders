precision highp float;

attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;

varying vec2 vUv;
varying vec3 vNormal;
varying vec3 vPosition;
varying float distFromCenter;

float rand(vec2 p){
    return abs(sin(dot(p, vec2(101.242, 3.10350)))*10420.013213) * 0.00023;
}

void main() {
    float angle = sin(time * 0.2) * 3.142;
    mat4 rotateX = mat4(1, 0, 0, 0, 0, cos(angle), sin(angle), 0, 0, -sin(angle), cos(angle), 0, 0, 0, 0, 1);
    mat4 rotateY = mat4(cos(angle), 0, -sin(angle), 0, 0, 1, 0, 0, sin(angle), 0, cos(angle), 0, 0, 0, 0, 1); // LOOKED UP
    vNormal = normal;
    vUv = uv;

    vec4 newPosition = position;
    newPosition.xyz *= rand(position.xy * (mouse * 0.4));

    newPosition = newPosition * rotateY * rotateX;

    vNormal = normalize(newPosition.xyz);  // LOOKED UP

    vPosition = newPosition.xyz;
    distFromCenter = length(newPosition);

    gl_Position = newPosition;
}
