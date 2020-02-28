#version 150

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

out vec4 outputColor;


void main () {
    vec2 coord = 20. * (gl_FragCoord.xy - resolution / 2.) / min(resolution.y, resolution.x);

    float len;

    for (int i = 0; i < 4; i++) {
        len = length(length(vec2(coord.x, coord.y)));

        coord.x = coord.x - cos(coord.y + sin(len)) + cos(time / 9.);
        coord.y = coord.y + sin(coord.x + cos(len)) + sin(time / 12.);
    }

    outputColor = vec4(cos(len * 2.), cos(len), cos(len), 1.);
}
