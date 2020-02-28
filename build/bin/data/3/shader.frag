#version 150

uniform vec2 resolution;
uniform vec2 mouse;
uniform highp float time;

out vec4 outputColor;

float random (vec2 st) {
return fract(sin(dot(st.xy,
  vec2(12.9898,78.233)))*
  43758.5453123);
}

void main() {
    vec2 st = gl_FragCoord.xy/resolution.xy;

st *= 5.;
st = sin(st)*time;

//if (time >= 1.) {
//	 st *= mouse.y, 1.;
// }

vec2 ipos = floor(st);
vec2 fpos = fract(st);

vec3 color = vec3(random( ipos ), sin(.1 * time), 0.5);

//color = vec3(fpos,0.0);

    outputColor = vec4(color,1.);
}
