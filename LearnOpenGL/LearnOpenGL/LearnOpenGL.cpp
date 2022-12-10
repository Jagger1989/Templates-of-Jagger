#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    GLFWwindow* window;

    if (glfwInit() != GLEW_OK)
    {
        return -1;
    }
    window = glfwCreateWindow(200, 200, "LearnOpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    float positions[] = {
        -0.5, -0.5f,
        0.0f, 0.5f,
        0.5, -0.5,
        0.5, -0.5
    };

    unsigned int indices[] = {
        0,1,2,0,2,3
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 4);
        glfwSwapBuffers(window);

    }
    glfwTerminate();
    return 0;
}
