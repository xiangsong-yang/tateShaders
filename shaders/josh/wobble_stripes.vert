precision highp float;

attribute vec4 position;
attribute vec3 normal;
attribute vec2 uv;

uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;

varying vec4 vPosition;
varying vec3 vNormal;
varying vec2 vUv;

vec3 wobble(vec3 v, vec3 n){
    vec3 newP1 = v + n*abs(sin(v.z * (sin(time) * 10.0)*2.0)) * 0.1;
    vec3 newP2 = v + n*abs(cos(v.y * (sin(time) *  8.0)*3.0)) * 0.1;
    vec3 ret   = (newP1 + newP2) * 0.5;

    return ret;
}

vec4 rotateY(vec4 v, float t){
    mat4 MY = mat4(cos(t), 0, -sin(t), 0, sin(t), cos(t), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
    return v*MY;
}

void main() {

    vec4 newPosition = position;

    newPosition.xy /= resolution;

    newPosition.xyz = wobble(newPosition.xyz, normal);
    newPosition = rotateY(newPosition, time*0.5);

    vPosition = newPosition;
    vNormal = normalize(newPosition.xyz);
    vUv = uv;
    gl_Position = vec4( vPosition );

}
