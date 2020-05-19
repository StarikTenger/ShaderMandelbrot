uniform vec2     iResolution;           // viewport resolution (in pixels)
uniform float     iTime;           // viewport resolution (in pixels)
uniform vec2 camPos;
uniform float scale;
uniform int mode;

#define PI 3.141693
#define INF 1e9
#define MAX_DIST 2
#define STEPS 100

// Math
vec2 multiply(vec2 a, vec2 b) {
	return vec2(a.x*b.x - a.y*b.y, a.y*b.x + a.x*b.y);
}

int count(vec2 p) {
	vec2 z = p;
	for(int i = 0; i < STEPS; i++) {
		
		z = multiply(z, z);
		z += p;
		if(distance(vec2(0, 0), z) > MAX_DIST)
			return i;
	}
	return STEPS;
}

void main() {
	vec2 uv = (gl_FragCoord - iResolution/2) / scale + camPos;

	

	int n = count(uv);
	float p = float(n) / STEPS;
	if(n == STEPS)
		p = 0;

	gl_FragColor = dvec4(p, p, p, 1);
}