#version 400
#extension GL_NV_gpu_shader_fp64: enable

uniform vec2     iResolution;           // viewport resolution (in pixels)
uniform float iTime;           // viewport resolution (in pixels)
uniform vec2 camPos;
uniform vec2 camSubPos;
uniform float scale;
uniform int mode;

#define PI 3.141693
#define INF 1e9
#define MAX_DIST 2
#define STEPS 100


// Math
f64vec2 multiply(f64vec2 a, f64vec2 b) {
	return f64vec2(a.x*b.x - a.y*b.y, a.y*b.x + a.x*b.y);
}

int count(f64vec2 p) {
	f64vec2 z = p;
	z += f64vec2(0.0f, 0.0f);
	for(int i = 0; i < STEPS; i++) {
		
		z = multiply(z, z);
		z += p;
		if(distance(f64vec2(0.0f, 0.0f), z) > MAX_DIST)
			return i;
	}
	return STEPS;
}

void main() {
	f64vec2 cam = f64vec2(camPos) + f64vec2(camSubPos) / 1000000.;
	f64vec2 uv = f64vec2((gl_FragCoord.xy - iResolution/2)) / scale + f64vec2(cam);

	

	int n = count(uv);
	double p = double(n) / STEPS;
	if(n == STEPS)
		p = 0;

	gl_FragColor = vec4(p, p, p, 1);
}