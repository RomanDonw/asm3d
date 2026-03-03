%ifndef GLAD_INC
%define GLAD_INC

; int (void (*proc)(const char *name))
extern gladLoadGLLoader

; void (int x, int y, int width, int height)
extern glViewport

; void (float r, float g, float b, float alpha)
extern glClearColor

%endif