in vec4 gl_FragCoord ;

uniform sampler2D texture;

vec2 pos = gl_FragCoord.xy/vec2(100.0);//screen cords



void main(){
	vec4 pixel = texture2D(texture,gl_TexCoord[0].xy);
	vec4 lighting = vec4(1.0,0.0,0.0,1.0);
	gl_FragColor = pixel*lighting;
}