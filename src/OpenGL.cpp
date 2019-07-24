/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenGL.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:59:07 by ppreez            #+#    #+#             */
/*   Updated: 2019/07/24 14:31:22 by ppreez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenGL.hpp"

float OpenGL::m_vertices[] = 
{
    1.0, 1.0,
    1.0, -1.0,
    -1.0, -1.0,
    -1.0, 1.0
};

unsigned int OpenGL::m_indices[] =
{
    0, 1, 3,
    1, 2, 3
};

OpenGL::OpenGL()
:m_screen_width(800), m_screen_height(600)
{
    initialise();
}

OpenGL::OpenGL(unsigned int width, unsigned int height)
:m_screen_width(width), m_screen_height(height)
{
    initialise();
}

OpenGL::OpenGL(OpenGL const &rhs)
{
    *this = rhs;
}

OpenGL &OpenGL::operator=(OpenGL const &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return *this;
}

OpenGL::~OpenGL()
{
    delete m_shader;
    glfwTerminate();
}

// Private methods

void OpenGL::initialise()
{
    if (!glfwInit())
        throw std::exception();
        
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwSetErrorCallback(error_callback);
    
}

void OpenGL::error_callback(int error, const char *description)
{
    std::cout << "OpenGL error: " << error << std::endl;
    std::cout << "OpenGL error: " << description << std::endl;
}

// Public methods

void OpenGL::createWindow()
{
    int height, width;
    

    float vertices[] = 
    {
         1.0,  1.0,
         1.0, -1.0,
        -1.0, -1.0,
        -1.0,  1.0
    };
    

    unsigned int indices[] =
    {
        0, 1, 3,
        1, 2, 3
};


    m_window = glfwCreateWindow(m_screen_width, m_screen_height, "Nibbler", nullptr, nullptr);
    if (!m_window)
        throw std::exception();
    glfwMakeContextCurrent(m_window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(m_window, &width, &height);
    glViewport(0, 0, width, height);
    m_shader = new Shader("./shaders/vertex.vs", "./shaders/fragment.fs");

    if (m_shader->m_errors)
    {
        glfwTerminate();
        exit(1);
    }
    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    glGenBuffers(1, &m_elementBuffer);

    glBindVertexArray(m_vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);

}

void OpenGL::closeWindow()
{
    glfwTerminate();
}

unsigned int OpenGL::retrieveInput()
{
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        return 0;
    else
        return 1;
}

void OpenGL::refresh()
{
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    m_shader->use();
    glBindVertexArray(m_vertexArray);
    glViewport(20, 20, 20, 20);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glViewport(0, 0, 20, 20);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void OpenGL::drawEntity(IEntity const &entity)
{
    (void)entity;
}