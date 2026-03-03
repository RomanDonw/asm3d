%ifndef GLFW_INC
%define GLFW_INC

; int (void)
extern glfwInit

; void (void)
extern glfwTerminate

; void (int option, int value)
extern glfwWindowHint

; GLFWwindow *(int width, int height, const char *title, GLFWmonitor *mon, GLFWwindow *share)
extern glfwCreateWindow

; void (GLFWwindow *)
extern glfwDestroyWindow

; void (GLFWwindow *)
extern glfwMakeContextCurrent

; GLFWglproc (const char *procname)
extern glfwGetProcAddress

; int (GLFWwindow *window)
extern glfwWindowShouldClose

; void (GLFWwindow *window, int state)
extern glfwSetWindowShouldClose

; void (GLFWwindow *window)
extern glfwSwapBuffers

; void (void)
extern glfwPollEvents

; int (GLFWwindow *window, int key)
extern glfwGetKey

%define GLFW_CONTEXT_VERSION_MAJOR 22002h
%define GLFW_CONTEXT_VERSION_MINOR 22003h

%define GLFW_OPENGL_PROFILE 22008h

%define GLFW_OPENGL_CORE_PROFILE 32001h

%define GLFW_RELEASE 0
%define GLFW_PRESS 1

%define GLFW_KEY_ESCAPE 256

%endif