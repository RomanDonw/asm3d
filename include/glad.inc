%ifndef GLAD_INC
%define GLAD_INC

; int (void (*proc)(const char *name))
extern gladLoadGLLoader

; void (int x, int y, int width, int height)
extern glViewport

; void (float r, float g, float b, float alpha)
extern glClearColor

%define GL_COLOR_BUFFER_BIT 4000h
%define GL_DEPTH_BUFFER_BIT 100h

; void (uint mask)
extern glClear

%define GL_TRIANGLES 4

%define GL_CULL_FACE 0B46h
%define GL_DEPTH_TEST 0B71h

; void (uint option)
extern glEnable

; void (uint option)
extern glDisable

%define GL_NONE 0
%define GL_FRONT 404h
%define GL_BACK 405h
%define GL_FRONT_AND_BACK 408h

; void (uint option)
extern glCullFace

; int (uint program, const char *name)
extern glGetUniformLocation

; uint (void)
extern glCreateProgram

; void (uint program)
extern glDeleteProgram

%define GL_FRAGMENT_SHADER 8B30h
%define GL_VERTEX_SHADER 8B31h

; uint (uint type)
extern glCreateShader

; void (uint shader)
extern glDeleteShader

; void (GLuint shader, int count, const char **source, const int *length)
extern glShaderSource

%endif