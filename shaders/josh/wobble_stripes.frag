precision highp float;

uniform vec2 resolution;
uniform vec2 mouse;
uniform float time;

varying vec4 vPosition;
varying vec3 vNormal;
varying vec2 vUv;

void main() {
    vec3 colour = vec3(0.8);
    vec3 light = vec3(30.0);

    vec3 red = vec3(1.0, 0.0, 0.0);
    vec3 blue = vec3(0.0, 0.0, 1.0);
    vec3 green = vec3(0.0, 1.0, 0.0);
    vec3 yellow = vec3(1.0, 0.0, 1.0);

    vec3 l = normalize(vPosition.xyz - normalize(light));
    vec3 n = normalize(vNormal);
    float diffuse = max(0.0, dot(n, l));
    float shade = dot(vNormal, normalize(light));
    float stripes = smoothstep(0.5, 1.0, abs(sin(vUv.y*vUv.x * 20.0 + time))) * 3.0;

    vec3 colourA = mix(red, blue, diffuse);
    vec3 colourB = mix(green, yellow, diffuse);

    colour *= mix(colourA, colourB, stripes);

    //shade = clamp(exp(shade), -0.3, 2.0);

    colour *= smoothstep(-1.0, 1.0, shade);

    gl_FragColor = vec4(colour,1.0);
}
