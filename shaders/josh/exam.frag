precision highp float;

uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;

varying vec2 vUv;
varying vec3 vNormal;
varying vec3 vPosition;
varying float distFromCenter;

void main() {
    float angle = (time * 2.0);
    mat4 rotateX = mat4(1, 0, 0, 0, 0, cos(angle), sin(angle), 0, 0, -sin(angle), cos(angle), 0, 0, 0, 0, 1);
    mat4 rotateY = mat4(cos(angle), 0, -sin(angle), 0, 0, 1, 0, 0, sin(angle), 0, cos(angle), 0, 0, 0, 0, 1); // LOOKED UP

    vec4 light = normalize(vec4(0.0, 80.0, -100.0, 1.0));
    vec4 light2 = normalize(vec4(0.0, 80.0, -100.0, 1.0));


    light *= rotateY;
    light2 *= rotateX;
    float direction = clamp(dot(light.xyz, vPosition), 0.0, 1.0);
    float direction2 = clamp(dot(light2.xyz, vPosition), 0.0, 1.0);

    //vec2 colour = ((gl_FragCoord.xy) * distFromCenter/resolution) * vUv * (direction * 0.05);

    vec3 colour = vec3(1.0);

    //float multiplier1 = (1.0 - abs(sin(pow(distFromCenter, 2.0)))) * 0.3;
    //float multiplier2 = pow(distFromCenter, 4.0)* 0.4;

    //colour.r *= multiplier1 + multiplier2 * 0.3  * (direction * multiplier1) * direction2 * 0.02;
    //colour.g *= multiplier1 + multiplier2 * (direction * multiplier1) * direction2 * 0.02;
    //colour.b *= multiplier1 + multiplier2 * 0.5 * (direction * multiplier1) * direction2 * 0.02;

    colour.r -= 0.3 * distFromCenter * (direction * 1.0-direction2);
    colour.g -= 0.6 * distFromCenter * (direction * 1.0-direction2);
    colour.b -= 0.4 * distFromCenter * (direction * 1.0-direction2);

    colour += vec3(0.05);

    colour.xy *= vUv;



    //vec2 colour = (1.0, 1.0);
    gl_FragColor = vec4(colour,1.0);
}
