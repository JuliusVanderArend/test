in vec4 gl_FragCoord ;

uniform sampler2D texture;
uniform sampler2D normal;
uniform vec2 lightPos[128];
uniform vec3 lightCol[128];
uniform float lightI[128];
uniform vec2 screenSize;


void main(){
	vec2 scaleFactor = vec2(screenSize.x/160.0,screenSize.y/90.0);
	vec2 pos = vec2(floor(gl_FragCoord.x/scaleFactor.x*2.0)*scaleFactor.x*0.5,floor(gl_FragCoord.y/scaleFactor.y*2.0)*scaleFactor.y*0.5);

	float lightingFactor = 1.0;
	vec4 pixel = texture2D(texture,gl_TexCoord[0].xy);
	if(pixel.r==1.0 && pixel.g ==1.0 && pixel.b == 1.0){
		gl_FragColor = pixel;
		//lightingFactor = 10.0;
	}
	vec4 pixelNormal = texture2D(normal,gl_TexCoord[0].xy);
	vec4 lighting = vec4(0.05,0.05,0.1,1.0);
	for(int i=0;i<128;i++){
		vec2 diff = lightPos[i]*vec2(scaleFactor.x,1.0)+vec2(0.0,scaleFactor.y)-pos;
		vec2 l = normalize(diff);// see if I can get rid of the normalize
		lighting += (vec4(lightCol[i].r,lightCol[i].g,lightCol[i].b,0.0)*lightI[i] * (dot(l,pixelNormal.xy)+2.0))*lightingFactor / (diff.x*diff.x+diff.y*diff.y);
	}
	gl_FragColor = pixel*lighting; //vec4(pos.x/1000,pos.y/1000,0.0,1.0);
}