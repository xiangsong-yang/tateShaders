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

    vec3 warm = vec3(0.8, 0.4, 0.1) + colour * 0.45;
    vec3 cool = vec3(0.0, 0.3, 0.8) + colour * 0.45;

    vec3 red = vec3(1.0, 0, 0);
    vec3 blue = vec3(0, 0, 1.0);

    float stripes = step(0.2, (fract(vUv.x * 10.0 + time*0.5)));

    vec3 l = normalize(vPosition.xyz - normalize(light));
    vec3 n = normalize(vNormal);

    float diffuse = max(0.0, dot(n, l));

    //float shade = clamp(dot(vNormal, normalize(light)), -0.4, 1.0);
    float shade = (dot(vNormal, normalize(light)));

    vec3 colourA = mix(cool, warm, diffuse);
    vec3 colourB = mix(red, blue, diffuse);
    colour = mix(colourA, colourB, stripes);
    colour *= smoothstep(-1.0, 0.3, shade);




    gl_FragColor = vec4(colour, 1.0);
}
