#ifdef GL_ES
precision mediump float;
#endif

varying vec2 v_texCoord;

void main( void ) {
    float len = length(v_texCoord);
    vec2 uv = vec2(v_texCoord.x - (v_texCoord.x / len) * cos(len - CC_Time[1]) * 0.05,
                   v_texCoord.y - (v_texCoord.y / len) * sin(len * 12.0 - CC_Time[1] * 7.0) * 0.05);
    gl_FragColor = texture2D(CC_Texture0, uv);
}