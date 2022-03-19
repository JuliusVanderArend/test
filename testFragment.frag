in vec4 gl_FragCoord ;

uniform sampler2D texture;
uniform sampler2D normal;
uniform vec2 lightPos[128];
uniform vec3 lightCol[128];
uniform float lightI[128];

vec2 pos = gl_FragCoord.xy;//screen cords



void main(){
	vec4 pixel = texture2D(texture,gl_TexCoord[0].xy);
	vec4 pixelNormal = texture2D(normal,gl_TexCoord[0].xy);
	vec4 lighting = vec4(0.05,0.05,0.1,1.0);
	for(int i=0;i<128;i++){
		vec2 diff = lightPos[i]-pos;
		lighting+=(vec4(lightCol[i].r,lightCol[i].g,lightCol[i].b,0.0)*lightI[i])/(diff.x*diff.x+diff.y*diff.y);
	}
	gl_FragColor = pixel*lighting;
}