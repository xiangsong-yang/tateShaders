#ifdef GL_ES
precision highp float;
#endif

uniform float u_time;
uniform vec2 u_resolution;


void main( void ) {
    vec2 coord = 20. * (gl_FragCoord.xy - u_resolution / 2.) / min(u_resolution.y, u_resolution.x);

    float len;

    for (int i = 0; i < 4; i++) {
        len = length(length(vec2(coord.x, coord.y)));

        coord.x = coord.x - cos(coord.y + sin(len)) + cos(u_time / 9.);
        coord.y = coord.y + sin(coord.x + cos(len)) + sin(u_time / 12.);
    }

    gl_FragColor = vec4(cos(len * 2.), cos(len), cos(len), 1.);
}
