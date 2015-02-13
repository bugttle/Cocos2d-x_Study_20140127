#ifdef GL_ES
precision lowp float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

// Gray scale(RGB)
const vec3 grayScale = vec3(0.298912, 0.586611, 0.114478);

void main(void) {
    vec4 color = texture2D(CC_Texture0, v_texCoord);
    float grayScaleColor = dot(color.rgb, grayScale);
    gl_FragColor = vec4(vec3(grayScaleColor), color.a);
}
