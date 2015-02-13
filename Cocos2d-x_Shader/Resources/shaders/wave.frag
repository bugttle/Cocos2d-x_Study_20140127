#ifdef GL_ES
precision highp float;
#endif

uniform vec2 resolution;
uniform vec2 touchPosition;

varying vec2 v_texCoord;

void main(void) {
    vec2 tc = v_texCoord;
    vec2 p = vec2(tc.x-touchPosition.x, tc.y-touchPosition.y);
    float len = length(p);
    vec2 uv = tc + (p / len) * cos(len * 14.0 - CC_Time[1] * 8.0) * 0.04;
    vec3 col = texture2D(CC_Texture0, uv).xyz;
    gl_FragColor = vec4(col, 1.0);
}
