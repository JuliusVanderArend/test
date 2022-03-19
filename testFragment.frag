in vec4 gl_FragCoord ;
vec2 pos = gl_FragCoord.xy/vec2(100.0);

void main(){
	gl_FragColor = vec4(pos.x,pos.y,0.0,1.0);
}