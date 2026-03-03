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

%endif