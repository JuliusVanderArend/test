in vec4 gl_FragCoord ;

uniform sampler2D texture;
uniform sampler2D normal;

vec2 pos = gl_FragCoord.xy/vec2(100.0);//screen cords



void main(){
	vec4 pixel = texture2D(texture,gl_TexCoord[0].xy);
	vec4 pixelNormal = texture2D(normal,gl_TexCoord[0].xy);
	vec4 lighting = vec4(0.2,0.0,0.0,1.0);
	gl_FragColor = pixel*pixelNormal+lighting;
}